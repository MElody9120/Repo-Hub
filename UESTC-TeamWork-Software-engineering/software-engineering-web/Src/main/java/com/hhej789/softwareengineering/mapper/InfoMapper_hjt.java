package com.hhej789.softwareengineering.mapper;

import com.hhej789.softwareengineering.bean.Info;
import com.hhej789.softwareengineering.bean.RequestExchange;
import org.apache.ibatis.annotations.*;

import org.springframework.stereotype.Repository;

@Mapper
@Repository
public interface InfoMapper_hjt {

    //更新信息表状态
    @Update("update Info set deal_member_id=#{deal_member_id}, `status`=1 where info_id=#{info_id}")
    public void checkRequestI(Integer info_id, Integer deal_member_id);

    //用户发布信息
    @Options(useGeneratedKeys = true, keyProperty = "info_id")
    @Insert("insert into Info(sort_id, public_member_id, good_id, status, scan_num, public_date) values " +
                            "(#{sort_id}, #{public_member_id}, #{good_id}, #{status}, #{scan_num}, #{public_date})")
    public void publishInfo(Info info);

    //获取发布信息表的状态
    @Select("select status from Info where info_id=#{info_id}")
    public Integer getInfoStatus(Integer info_id);

    //根据信息表id查询发布商品id
    @Select("select good_id from Info where info_id=#{info_id}")
    public Integer getGoodIdByInfoId(Integer info_id);

}
