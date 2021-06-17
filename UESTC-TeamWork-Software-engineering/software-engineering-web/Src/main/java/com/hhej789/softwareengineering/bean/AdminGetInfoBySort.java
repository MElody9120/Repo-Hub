package com.hhej789.softwareengineering.bean;

import lombok.Data;

/**
 * @author gybin___NN
 * @data 2020 - 05 - ${DATA} - 17:02
 */
@Data
public class AdminGetInfoBySort {

    private Integer info_id;
    private Integer sort_id;
    private Integer public_member_id;
    private String good_name;
    private String good_description;
    private Integer status;
    private String public_date;
    private Integer scan_num;
    private Integer deal_member_id;
    private Integer request_member_id;
    private String exchange_good_name;
    private String exchange_good_description;
    private Integer request_status;

}
