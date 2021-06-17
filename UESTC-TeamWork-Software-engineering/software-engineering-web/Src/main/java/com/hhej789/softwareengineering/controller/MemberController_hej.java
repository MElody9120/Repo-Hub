package com.hhej789.softwareengineering.controller;

import com.hhej789.softwareengineering.bean.Member;
import com.hhej789.softwareengineering.mapper.MemberMapper_hej;
import com.hhej789.softwareengineering.tools.MD5Util_hej;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.ValueOperations;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.Objects;
import java.util.UUID;
import java.util.concurrent.TimeUnit;

/**
 * @ClassName MemberController
 * @Description TODO
 * @Author AICHI
 * @Date 2020/4/23 10:36
 * @Version 1.0
 */

@RestController
public class MemberController_hej {

    @Autowired
    MemberMapper_hej memberMapperHej;

    @Autowired
    RedisTemplate redisTemplate;

    //测试
    @GetMapping("/test")
    public void test() {

    }

    //用户注册
    @PostMapping("/member/register")
    public HashMap<String,Object> register(Member member) {

        HashMap map = new HashMap();

        try {
            if(Objects.isNull(memberMapperHej.getUser(member.getMember_name()))) {  //判断用户是否已存在
                if (member.getPassword().length() <6)   //判断输入密码是否小于6位
                    map.put("msg", "密码不能小于6位，注册失败");
                else {                       //MD5盐值加密密码并注册
                    memberMapperHej.register(MD5Util_hej.getMD5(member.getMember_name(), member.getPassword()), member.getMember_name(),
                            member.getWechat_id(), member.getPhone_num());
                    map.put("msg", "注册成功！");
                    System.out.println("用户" + member.getMember_name() + "注册成功");
                }
            }
            else {
                map.put("msg", "用户名已存在，注册失败！");
            }
        } catch (Exception e) {
            System.out.println(e);
            map.put("msg", "请求错误！");
        }

        return map;
    }

    //用户登录
    @PostMapping("/member/login")
    public HashMap<String,Object> login(Member member) {

        HashMap map = new HashMap();

        try {
            String md5 = MD5Util_hej.getMD5(member.getMember_name(), member.getPassword());     //盐值加密密码

            if (Objects.isNull(memberMapperHej.getUser(member.getMember_name())))   //判断用户是否存在
                map.put("msg","用户名不存在，登录失败！");
            else if(memberMapperHej.getUser(member.getMember_name()).getPassword().equals(md5)) {   //判断加密后密码是否正确
                ValueOperations ops = redisTemplate.opsForValue();
                if(Objects.isNull(ops.get(member.getMember_name()))) {  //判断用户是否已登录
                    String token = UUID.randomUUID().toString();
                    ops.set(member.getMember_name(), token, 10, TimeUnit.MINUTES);
                    ops.set(token, member.getMember_name(), 10, TimeUnit.MINUTES);
                    System.out.println("用户" + member.getMember_name() + "登录成功！");
                } else {
                    redisTemplate.expire(member.getMember_name(), 10, TimeUnit.MINUTES);
                    redisTemplate.expire(ops.get(member.getMember_name()), 10, TimeUnit.MINUTES);
                    System.out.println("用户" + member.getMember_name() + "已登录！");
                }
                map.put("msg", "登录成功！");
                map.put("token", ops.get(member.getMember_name()));
            }
            else {
                map.put("msg", "密码错误，登录失败！");
                System.out.println("用户" + member.getMember_name() + "密码输入错误，登录失败！");
            }
        } catch (Exception e) {
            System.out.println(e);
            map.put("msg", "请求错误！");
        }
        return map;
    }

    //用户注销
    @PostMapping("/member/loginOut")
    public HashMap<String,Object> loginOut(@RequestHeader("token") String token) {

        HashMap map = new HashMap();

        try{
            ValueOperations ops = redisTemplate.opsForValue();
            Boolean isLogin = redisTemplate.hasKey(token);
            if(isLogin) {
                final Object member_id = ops.get(token);
                redisTemplate.delete(token);
                redisTemplate.delete(member_id);
                map.put("msg", "注销成功！");
                System.out.println("用户" + member_id + "已注销！");
            }
            else {
                map.put("msg", "用户未登录！");
            }
        } catch (Exception e) {
            map.put("msg", "请求失败！");
        }

        return map;
    }

}
