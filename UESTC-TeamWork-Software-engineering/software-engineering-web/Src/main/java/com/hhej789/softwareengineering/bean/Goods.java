package com.hhej789.softwareengineering.bean;

import lombok.Data;

/**
 * @ClassName Goods
 * @Description TODO
 * @Author AICHI
 * @Date 2020/4/24 15:53
 * @Version 1.0
 */
@Data
public class Goods {

    private Integer good_id;
    private String good_name;
    private String good_description;
    private Integer owner_id;
    private Integer status;
    private Integer is_public_or_request;

}
