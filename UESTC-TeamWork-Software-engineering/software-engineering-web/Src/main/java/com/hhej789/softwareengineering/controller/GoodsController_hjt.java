package com.hhej789.softwareengineering.controller;

import com.hhej789.softwareengineering.bean.Goods;
import com.hhej789.softwareengineering.mapper.GoodsMapper_hjt;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.util.HashMap;
import java.util.UUID;

@RestController
public class GoodsController_hjt {

    @Autowired
    GoodsMapper_hjt goodsMapper_hjt;

    //用户上传闲置物品
    @PostMapping("/member/uploadGood")
    public HashMap<String,Object> uploadGood(Goods goods, MultipartFile image){

        HashMap<String,Object> map = new HashMap<>();

        try {

            goods.setStatus(0);
            goodsMapper_hjt.uploadGood(goods);

            String imgDirPath = new String("src/main/resources/static/uploadImg");
            File imgDir = new File(imgDirPath);
            String url = UUID.randomUUID() + image.getOriginalFilename();
            File newImg = new File(imgDir.getAbsolutePath() + File.separator + url);
            image.transferTo(newImg);
            goodsMapper_hjt.uploadImg(goods.getGood_id(),"/uploadImg/" + url);

            map.put("msg", "插入成功！");
            map.put("goods", goods);
            map.put("url", "/uploadImg/" + url);
        } catch (Exception e) {
            e.printStackTrace();
            map.put("msg", "插入失败！");
        }
        return map;
    }

}
