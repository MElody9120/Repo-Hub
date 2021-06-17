package com.hhej789.softwareengineering.interceptor;

import com.hhej789.softwareengineering.mapper.MemberMapper_hej;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.ValueOperations;
import org.springframework.util.StringUtils;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Objects;
import java.util.concurrent.TimeUnit;

/**
 * @ClassName AuthInterceptor
 * @Description TODO
 * @Author AICHI
 * @Date 2020/4/23 21:31
 * @Version 1.0
 */
public class AuthInterceptor_hej implements HandlerInterceptor {

    @Autowired
    MemberMapper_hej memberMapperHej;

    @Autowired
    RedisTemplate redisTemplate;

    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {

        JSONObject o = new JSONObject();

        response.setCharacterEncoding("UTF-8");
        response.setContentType("text/html;charset=utf-8");

        String token = request.getHeader("token");
        if(StringUtils.isEmpty(token)) {
            o.put("msg", "用户未登录，请登陆后操作！");
            response.getWriter().append(o.toString());
            return false;
        }
        ValueOperations ops = redisTemplate.opsForValue();
        Object loginStatus = ops.get(token);
        if(Objects.isNull(loginStatus)) {
            o.put("msg", "token错误，请查看！");
            response.getWriter().append(o.toString());
            return false;
        }
        redisTemplate.expire(token, 2, TimeUnit.MINUTES);
        redisTemplate.expire(ops.get(token), 2, TimeUnit.MINUTES);
        return true;
    }

    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {

    }

    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {

    }

}
