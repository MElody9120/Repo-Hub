package com.hhej789.softwareengineering.mapper;

import com.hhej789.softwareengineering.bean.GetDealMem;
import com.hhej789.softwareengineering.bean.MemberGetInfoById;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper
@Repository
public interface MemberMapper_lzr {

    //发布信息用户查看成交用户信息
    public List<GetDealMem> getInfoByDealId(Integer id);

    //用户分页查看个人发布的信息
    public List<MemberGetInfoById> getInfoByPublicId(Integer id,Integer page,Integer count);

    //统计用户分页查看个人发布的信息的数据的数量
    public Integer getInfoPublicIdByNum(Integer id);




}
