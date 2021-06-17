package com.hhej789.softwareengineering.config;

import com.hhej789.softwareengineering.interceptor.AuthInterceptor_hej;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName AuthConfig
 * @Description TODO
 * @Author AICHI
 * @Date 2020/4/23 21:45
 * @Version 1.0
 */

@Configuration
public class AuthConfig_hej implements WebMvcConfigurer {

    @Bean
    public AuthInterceptor_hej initAuthInterceptor() {
        return new AuthInterceptor_hej();
    }

    @Override
    public void addInterceptors(InterceptorRegistry registry) {

        List<String> add = new ArrayList();
        add.add("/admin/getMember");
        add.add("/admin/getInfo");
        add.add("/admin/getInfoBySort");
        add.add("/admin/getInfoByMemId");
        add.add("/member/uploadGood");
        add.add("/member/publishInfo");
        add.add("/member/checkRequest");
        add.add("/member/requestExchange");
        add.add("/member/getByInfoId/getDealMem");
        add.add("/member/getInfoById");
        add.add("/member/loginOut");

        List<String> exclude = new ArrayList();
        exclude.add("/admin/login");
        exclude.add("/member/register");
        exclude.add("/member/login");

        registry.addInterceptor(initAuthInterceptor()).addPathPatterns(add).excludePathPatterns(exclude);
    }
}
