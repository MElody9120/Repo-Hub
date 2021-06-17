/**
 * @ClassName InfoMapper_lzr
 * @Description TODO
 * @Author lzr
 * @Date 2020/4/24
 * @Version 1.0
 */
package com.hhej789.softwareengineering.mapper;


import com.hhej789.softwareengineering.bean.Info;
import com.hhej789.softwareengineering.bean.InfoSort;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.List;

@Mapper

@Repository

public interface InfoMapper_lzr {
    //分页查询已发布的信息
    public List<Info> getInfo(Integer page, Integer count);

    //统计已发布的信息的数据的数量
    public Integer getInfoCount();

    //分页模糊搜索已发布的信息
    public List<Info> getGoodsByName(String good_name, Integer page, Integer count);

    //统计模糊搜索已发布的信息数据的数量
    public Integer getGoodsNumByName(String good_name);

    //分页分类查询已发布的信息
    public List<InfoSort> getInfoSortById(Integer page, Integer sort_id, Integer count);

    //统计分类查询已发布的信息数据的数量
    public Integer getInfoSortNumById(Integer sort);

    //分页分类模糊搜索已发布的信息
    public List<Info> getInfoBySortKeyWord(Integer page,Integer id,String name,Integer count);

    //统计分页分类模糊搜索已发布的信息数据的数量
    public Integer getNumBySortKeyWord(Integer id,String name);

}
