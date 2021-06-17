package com.hhej789.softwareengineering.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

/**
 * @ClassName InfoSortMapper_gyb
 * @Description TODO
 * @Author AICHI
 * @Date 2020/5/7 10:55
 * @Version 1.0
 */
@Repository
@Mapper
public interface InfoSortMapper_gyb {

    @Select("select sort_name from InfoSort where sort_id=#{sort_id}")
    public String getInfoSortById(Integer sort_id);
}
