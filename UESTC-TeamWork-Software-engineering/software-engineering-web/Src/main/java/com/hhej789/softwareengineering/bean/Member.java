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
public class Member {

    private Integer member_id;
    private String password;
    private String member_name;
    private String wechat_id;
    private String phone_num;
    private String register_time;
    private String latest_login_time;

}
