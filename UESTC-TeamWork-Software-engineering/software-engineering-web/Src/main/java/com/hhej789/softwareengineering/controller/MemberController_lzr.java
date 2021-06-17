package com.hhej789.softwareengineering.controller;
/**
 * @ClassName InfoController_lzr
 * @Description TODO
 * @Author lzr
 * @Date 2020/4/24
 * @Version 1.0
 */

import com.hhej789.softwareengineering.mapper.MemberMapper_lzr;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@RestController
public class MemberController_lzr {
    @Autowired
    MemberMapper_lzr memberMapper_lzr;


    //发布信息用户查看成交用户信息 已完成 通过测试
    @GetMapping("/member/getByInfoId/getDealMem")
    public Map<String ,Object> getInfoDeal(@RequestParam("info_id") Integer id)
    {
        Map map = new HashMap();
        try
        {
            map.put("msg","查询成功");
            map.put("Member",memberMapper_lzr.getInfoByDealId(id));
        }catch (Exception e)
        {
            e.printStackTrace();
            map.put("msg","查询失败");
        }
        return map;
    }

    //用户分页查看个人发布的信息 已完成 通过测试
    @GetMapping("/member/getInfoById")
    public Map<String,Object> getInfoPublic(@RequestParam("page") Integer page,@RequestParam("public_member_id") Integer id)
    {
        Map map = new HashMap();
        try
        {
            map.put("Info",memberMapper_lzr.getInfoByPublicId(id,page,memberMapper_lzr.getInfoPublicIdByNum(id)));
            map.put("msg","查询成功");
        }catch (Exception e)
        {
            e.printStackTrace();
            map.put("msg","查询失败");
        }
        return map;
    }

}
