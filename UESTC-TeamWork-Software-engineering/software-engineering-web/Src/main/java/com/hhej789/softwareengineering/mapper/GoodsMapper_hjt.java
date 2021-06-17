package com.hhej789.softwareengineering.mapper;

import com.hhej789.softwareengineering.bean.Goods;
import org.apache.ibatis.annotations.*;
import org.springframework.stereotype.Repository;

@Mapper
@Repository
public interface GoodsMapper_hjt {

    //用户上传闲置物品
    @Options(useGeneratedKeys = true, keyProperty = "good_id")
    @Insert("insert into Goods(good_name, good_description, owner_id, status) values (#{good_name}, #{good_description}, #{owner_id}, #{status})")
    public void uploadGood(Goods goods);


    //上传图片
    @Insert("insert into Image(good_id, url) values (#{good_id}, #{url})")
    public void uploadImg(Integer good_id, String url);

    //依据good_name查出good_id
    @Select("select good_id from goods where good_name = #{good_name}")
    public Integer getGoodIdByName(String good_name);


    //查询闲置是否处于发布状态
    @Select("select is_public_or_request from Goods where good_id=#{good_id}")
    public Integer getIsPublicOrRequest(Integer good_id);

    //设置闲置是否处于发布状态
    @Update("update Goods set is_public_or_request=#{status} where good_id=#{good_id}")
    public void setIsPublicOrRequest(Integer good_id, Integer status);

    //查询闲置是否已交换
    @Select("select status from Goods where good_id=#{good_id}")
    public Integer getGoodStatus(Integer good_id);

    @Update("update Goods set status=#{status} where good_id=#{good_id}")
    //设置闲置交换状态
    public void setGoodStatus(Integer good_id, Integer status);

}
