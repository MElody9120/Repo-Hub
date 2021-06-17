package com.hhej789.softwareengineering.controller;

import com.hhej789.softwareengineering.bean.RequestExchange;
import com.hhej789.softwareengineering.mapper.GoodsMapper_hjt;
import com.hhej789.softwareengineering.mapper.RequestExchangeMapper_htj;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;

/**
 * @ClassName RequestExchangeController_hjt
 * @Description TODO
 * @Author AICHI
 * @Date 2020/5/7 10:03
 * @Version 1.0
 */
@RestController
public class RequestExchangeController_hjt {

    @Autowired
    RequestExchangeMapper_htj requestExchangeMapper_htj;

    @Autowired
    GoodsMapper_hjt goodsMapper_hjt;

    //请求用户请求交换闲置物品
    @PostMapping("/member/requestExchange")
    public HashMap<String,Object> requestExchange(RequestExchange requestExchange) {

        HashMap map = new HashMap();

        try {
            if(goodsMapper_hjt.getIsPublicOrRequest(requestExchange.getExchange_good_id()) == 0 &&      //判断是否处于发布或交换状态中
                    goodsMapper_hjt.getGoodStatus(requestExchange.getExchange_good_id()) == 0) {      //判断物品是否已交换
                requestExchange.setStatus(0);
                requestExchangeMapper_htj.requestExchange(requestExchange);
                goodsMapper_hjt.setIsPublicOrRequest(requestExchange.getExchange_good_id(), 1);
                map.put("msg", "请求交换成功！");
                map.put("requestExchange", requestExchange);
            } else if(goodsMapper_hjt.getIsPublicOrRequest(requestExchange.getExchange_good_id()) == 1) {
                map.put("msg", "物品处于发布或交换状态，不能请求交换！");
            } else {
                map.put("msg", "物品已交换，不能再次请求交换！");
            }
        } catch (Exception e) {
            map.put("msg","请求失败！");
            e.printStackTrace();
        }
        return map;
    }

}
