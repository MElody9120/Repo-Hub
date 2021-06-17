<<<<<<< Updated upstream:software-engineering-web/src/main/resources/sql/model.sql
CREATE TABLE `Member` (
`member_id` int(10) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '用户 id',
`password` char(32) NULL COMMENT '密码',
`member_name` char(20) NULL COMMENT '用户名',
`wechat_id` char(30) NULL COMMENT '微信号',
`phone_num` char(11) NULL COMMENT '手机号码',
`register_time` char(100) NULL COMMENT '注册时间',
`latest_login_time` char(100) NULL COMMENT '最近登录时间',
PRIMARY KEY (`member_id`) 
);
CREATE TABLE `InfoSort` (
`sort_id` int(4) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '信息分类 id',
`sort_name` char(20) NULL COMMENT '分类名称',
PRIMARY KEY (`sort_id`) 
);
CREATE TABLE `Info` (
`info_id` int(6) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '信息 id',
`sort_id` int(4) NULL COMMENT '信息分类 id',
`public_member_id` int(10) NULL COMMENT '发布用户 id',
`good_id` int(5) NULL COMMENT '物品 id',
`status` tinyint NULL DEFAULT 0 COMMENT '发布状态（发布中0，交换完成1，取消交换-1）',
`public_date` char(50) NULL COMMENT '发布日期',
`scan_num` int NULL COMMENT '浏览量',
`deal_member_id` int(10) NULL COMMENT '成交用户 id',
PRIMARY KEY (`info_id`) 
);
CREATE TABLE `RequestExchange` (
`request_id` int(8) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '请求 id',
`request_member_id` int(10) NULL COMMENT '请求用户 id',
`info_id` int(6) NULL COMMENT '信息 id',
`exchange_good_id` int(5) NULL COMMENT '交换物品 id',
`status` tinyint NULL DEFAULT 0 COMMENT '请求状态（请求中0，成交1，拒绝-1）',
PRIMARY KEY (`request_id`) 
);
CREATE TABLE `Admin` (
`admin_id` char(32) NOT NULL COMMENT '管理员id',
`password` char(32) NULL COMMENT '密码',
`admin_name` char(20) NULL COMMENT '管理员姓名',
PRIMARY KEY (`admin_id`) 
);
CREATE TABLE `Goods` (
`good_id` int(5) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '物品 id',
`good_name` char(20) NULL COMMENT '物品名称',
`good_description` char(200) NULL COMMENT '物品描述',
`owner_id` int(10) NULL COMMENT '所属用户 id',
`status` tinyint NULL DEFAULT 0 COMMENT '状态（默认0，已交换1）',
PRIMARY KEY (`good_id`) 
);
CREATE TABLE `Image` (
`img_id` int(10) UNSIGNED ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '图片 id',
`good_id` int(5) ZEROFILL NULL COMMENT '商品 id',
`url` char(50) NULL COMMENT '统一资源定位',
PRIMARY KEY (`img_id`) 
);
=======
CREATE TABLE `Member` (
`member_id` int(10) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '用户 id',
`password` char(32) NULL COMMENT '密码',
`member_name` char(20) NULL COMMENT '用户名',
`wechat_id` char(30) NULL COMMENT '微信号',
`phone_num` char(11) NULL COMMENT '手机号码',
`register_time` char(100) NULL COMMENT '注册时间',
`latest_login_time` char(100) NULL COMMENT '最近登录时间',
PRIMARY KEY (`member_id`) 
);
CREATE TABLE `InfoSort` (
`sort_id` int(4) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '信息分类 id',
`sort_name` char(20) NULL COMMENT '分类名称',
PRIMARY KEY (`sort_id`) 
);
CREATE TABLE `Info` (
`info_id` int(6) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '信息 id',
`sort_id` int(4) NULL COMMENT '信息分类 id',
`public_member_id` int(10) NULL COMMENT '发布用户 id',
`good_id` int(5) NULL COMMENT '物品 id',
`status` tinyint NULL DEFAULT 0 COMMENT '发布状态（发布中0，交换完成1，取消交换-1）',
`public_date` char(50) NULL COMMENT '发布日期',
`scan_num` int NULL COMMENT '浏览量',
`deal_member_id` int(10) NULL COMMENT '成交用户 id',
PRIMARY KEY (`info_id`) 
);
CREATE TABLE `RequestExchange` (
`request_id` int(8) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '请求 id',
`request_member_id` int(10) NULL COMMENT '请求用户 id',
`info_id` int(6) NULL COMMENT '信息 id',
`exchange_good_id` int(5) NULL COMMENT '交换物品 id',
`status` tinyint NULL DEFAULT 0 COMMENT '请求状态（请求中0，成交1，拒绝-1）',
PRIMARY KEY (`request_id`) 
);
CREATE TABLE `Admin` (
`admin_id` char(32) NOT NULL COMMENT '管理员id',
`password` char(32) NULL COMMENT '密码',
`admin_name` char(20) NULL COMMENT '管理员姓名',
PRIMARY KEY (`admin_id`) 
);
CREATE TABLE `Goods` (
`good_id` int(5) ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '物品 id',
`good_name` char(20) NULL COMMENT '物品名称',
`good_description` char(200) NULL COMMENT '物品描述',
`owner_id` int(10) NULL COMMENT '所属用户 id',
`status` tinyint NULL DEFAULT 0 COMMENT '状态（默认0，已交换1）',
PRIMARY KEY (`good_id`) 
);
CREATE TABLE `Image` (
`img_id` int(10) UNSIGNED ZEROFILL NOT NULL AUTO_INCREMENT COMMENT '图片 id',
`good_id` int(5) ZEROFILL NULL COMMENT '商品 id',
`url` char(50) NULL COMMENT '统一资源定位',
PRIMARY KEY (`img_id`) 
);
>>>>>>> Stashed changes:software-engineering-web/src/main/resources/sql/model.sql
