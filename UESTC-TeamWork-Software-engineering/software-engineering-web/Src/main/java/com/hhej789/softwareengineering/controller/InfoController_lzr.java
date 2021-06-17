package com.hhej789.softwareengineering.controller;
/**
 * @ClassName InfoController_lzr
 * @Description TODO
 * @Author lzr
 * @Date 2020/4/24
 * @Version 1.0
 */

import com.hhej789.softwareengineering.mapper.InfoMapper_lzr;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@RestController
public class InfoController_lzr {

    @Autowired
    InfoMapper_lzr infoMapperLzr;

    //分页查询已发布的信息 已完成 测试通过
    @GetMapping("/info/getInfo")
    public Map<String,Object> getInfo(@RequestParam("page") Integer page)
    {
        Map map = new HashMap();
        try
        {
            map.put("msg","查询成功");
            map.put("info",infoMapperLzr.getInfo(page,infoMapperLzr.getInfoCount()));

        }catch (Exception e)
        {
            e.printStackTrace();
            map.put("msg","查询失败");
        }
        return map;
    }

    //分页模糊搜索已发布的信息 已完成 测试通过
    @GetMapping("/info/getInfoByKeyword")
    public Map<String,Object> getGoodsByName(@RequestParam("page") Integer page, @RequestParam("Keyword") String good_name)
    {
        Map map = new HashMap();
        try
        {
            map.put("msg","查询成功");
            map.put("info",infoMapperLzr.getGoodsByName(good_name, page, infoMapperLzr.getGoodsNumByName(good_name)));
        }catch (Exception e)
        {
            e.printStackTrace();
            map.put("msg","查询失败");
        }
        return  map;
    }

    //分页分类查询已发布的信息 已完成 测试通过
    @GetMapping("/info/getInfoBySort")
    public Map<String,Object> getInfoSortByName(@RequestParam("page") Integer page, @RequestParam("sort_id") Integer sort_id)
    {
        Map map = new HashMap();
        try {
            map.put("msg","查询成功");
            map.put("info",infoMapperLzr.getInfoSortById(page,sort_id,infoMapperLzr.getInfoSortNumById(sort_id)));
        }catch (Exception e)
        {
            e.printStackTrace();
            map.put("msg","查询失败");
        }
        return  map;
    }
    //分页分类模糊搜索已发布的信息 已完成 测试通过
    @GetMapping("/info/getInfo/bySort/byKeyword")
    public Map<String,Object> getInfoBySortKeyWord(@RequestParam ("page") Integer page,@RequestParam("sort_id") Integer id,@RequestParam("keyword") String name)
    {
        Map map = new HashMap();
        try {
            map.put("msg","查询成功");
            map.put("info",infoMapperLzr.getInfoBySortKeyWord(page,id,name,infoMapperLzr.getNumBySortKeyWord(id,name)));
        }catch (Exception e)
        {
            e.printStackTrace();
            map.put("msg","查询失败");
        }
        return  map;
    }

}
