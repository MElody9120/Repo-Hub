package com.hhej789.softwareengineering.bean;

import lombok.Data;

/**
 * @ClassName Admin
 * @Description TODO
 * @Author AICHI
 * @Date 2020/4/24 15:50
 * @Version 1.0
 */
@Data
public class RequestExchange {

    private Integer request_id;
    private Integer request_member_id;
    private Integer exchange_good_id;
    private Integer info_id;
    private Integer status;

}
