package com.hhej789.softwareengineering.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

/**
 * @ClassName MemberMapper_gyb
 * @Description TODO
 * @Author AICHI
 * @Date 2020/5/7 11:07
 * @Version 1.0
 */
@Repository
@Mapper
public interface MemberMapper_gyb {

    @Select("select member_name from Member where member_id=#{member_id}")
    public String getMemberNameById(Integer member_id);
}
