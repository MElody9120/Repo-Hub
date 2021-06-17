package com.hhej789.softwareengineering.mapper;

import com.hhej789.softwareengineering.bean.*;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

/**x
 * @author gybin___NN
 * @data 2020 - 04 - ${DATA} - 16:07
 */
@Mapper
@Repository

public interface AdminMapper_gyb {

    /*管理员登陆*/
    public List<Member> getMember(Integer page,Integer count);
    public Integer getMemberbyNum();

    /*管理员分页查看已发布信息*/
    public List<AdminGetInfo> getInfo(Integer page,Integer count);
    public Integer getInfobyNum();

    /*管理员分页分类查看已发布信息*/
    public List<AdminGetInfoBySort>getInfoBySort(Integer page,Integer sort_id,Integer count);
    public Integer getInfoSortbyNum(Integer sort_id);

    /*管理员根据用户id分页查看已发布信息*/
    public List<AdminGetInfoByMemId>getInfoByMemId(Integer page,Integer member_id,Integer count);
    public Integer getInfoMemIdbyNum(Integer member_id);

    /*管理员登陆*/
    public Admin getAdmin(String admin_id);

}
