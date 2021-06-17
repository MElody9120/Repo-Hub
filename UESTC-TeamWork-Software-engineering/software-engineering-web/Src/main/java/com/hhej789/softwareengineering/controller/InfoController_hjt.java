package com.hhej789.softwareengineering.controller;

import com.hhej789.softwareengineering.bean.Goods;
import com.hhej789.softwareengineering.bean.Info;
import com.hhej789.softwareengineering.bean.RequestExchange;
import com.hhej789.softwareengineering.mapper.GoodsMapper_hjt;
import com.hhej789.softwareengineering.mapper.InfoMapper_hjt;
import com.hhej789.softwareengineering.mapper.RequestExchangeMapper_htj;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;

@RestController
public class InfoController_hjt {

    @Autowired
    InfoMapper_hjt infoMapper_hjt;

    @Autowired
    GoodsMapper_hjt goodsMapper_hjt;

    @Autowired
    RequestExchangeMapper_htj requestExchangeMapper_htj;

    //用户发布信息
    @PostMapping("/member/publishInfo")
    public HashMap<String,Object> insertInfo(Info info) {
        HashMap map = new HashMap();
        try{
            if(goodsMapper_hjt.getIsPublicOrRequest(info.getGood_id()) == 0 && goodsMapper_hjt.getGoodStatus(info.getGood_id()) == 0) {
                info.setStatus(0);
                info.setScan_num(0);
                SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式
                info.setPublic_date(df.format(new Date()));
                infoMapper_hjt.publishInfo(info);
                goodsMapper_hjt.setIsPublicOrRequest(info.getGood_id(), 1);
                map.put("msg", "发布成功！");
                map.put("info", info);
            } else {
                map.put("msg", "此商品处于发布状态或已交换，请确认！");
            }
        } catch (Exception e) {
            e.printStackTrace();
            map.put("msg", "请求错误！");
        }
        return map;
    }

    //发布用户审核交换请求
    @PutMapping("/member/checkRequest")
    public HashMap<String, Object> checkRequest(RequestExchange requestExchange) {

        HashMap map = new HashMap();

        try{
            Integer info_id = requestExchangeMapper_htj.getRequestChangeById(requestExchange.getRequest_id()).getInfo_id();
            if(infoMapper_hjt.getInfoStatus(info_id) == 0) {
                requestExchangeMapper_htj.checkRequestR(requestExchange.getRequest_id(), requestExchange.getStatus());
                if (requestExchange.getStatus() == 1) {
                    Integer request_member_id = requestExchangeMapper_htj.getRequestChangeById(requestExchange.getRequest_id()).getRequest_member_id();
                    infoMapper_hjt.checkRequestI(info_id, request_member_id);
                    Integer request_good_id = requestExchangeMapper_htj.getRequestChangeById(requestExchange.getRequest_id()).getExchange_good_id();
                    Integer public_good_id = infoMapper_hjt.getGoodIdByInfoId(info_id);
                    goodsMapper_hjt.setGoodStatus(request_good_id, 1);
                    goodsMapper_hjt.setGoodStatus(public_good_id, 1);
                    map.put("msg", "请求通过成功！");
                } else {
                    map.put("msg", "请求拒绝成功！");
                }
            } else {
                map.put("msg", "此信息已完成交易，不能再次提交！");
            }
        } catch (Exception e) {
            map.put("msg", "请求失败！");
            e.printStackTrace();
        }
        return map;
    }

}
