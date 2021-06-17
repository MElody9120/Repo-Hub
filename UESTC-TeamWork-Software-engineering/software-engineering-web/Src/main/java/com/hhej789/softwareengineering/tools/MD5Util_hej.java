package com.hhej789.softwareengineering.tools;

import org.springframework.util.DigestUtils;

/**
 * @ClassName MD5Util
 * @Description TODO
 * @Author AICHI
 * @Date 2020/4/23 22:37
 * @Version 1.0
 */
public class MD5Util_hej {

    //盐，用于混交md5
    private static String salt = "asdwqAsd12_qS";

    /**
     * 生成md5
     */
    public static String getMD5(String member_name, String password) {
        String base = member_name + "/" + password + "/" + salt;
        String md5 = DigestUtils.md5DigestAsHex(base.getBytes());
        System.out.println("md5盐加密");
        return md5;
    }

}
