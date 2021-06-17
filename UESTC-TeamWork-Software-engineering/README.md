# Software-engineering

### 接口定义

备注：除管理员登录、用户登陆注册外，所有请求必须带请求头token

#### 管理员 /admin

- 管理员登录 /login

```api
请求方式：POST
入参：admin_id、password
出参：
{
	"msg":"登录成功"
	"token":token
}
```

- 管理员分页查看用户信息 /getMember

```api
请求方式：POST
入参：page
出参：
{
	"msg":"查询成功"
	"Member":Member
}
```

- 管理员分页查看已发布的信息 /getInfo

```api
请求方式：POST
入参：page
出参：
{
	"msg":"查询成功"
	"info":[
		info_id:
		sort_id:
		public_member_id
		good_name:
		good_description:
		status:交易状态
		public_date:
		scan_num:
		deal_member_id:
		request_member_id:
		exchange_good_name:
		exchange_good_description:
		reqreuest_status:请求状态
	]
}
```

- 管理员分页分类查看已发布的信息 /getInfoBySort

```api
请求方式：POST
入参：page、sort_id
出参：
{
	"msg":"查询成功"
	"info":[
		info_id:
		sort_id:
		public_member_id
		good_name:
		good_description:
		status:交易状态
		public_date:
		scan_num:
		deal_member_id:
		request_member_id:
		exchange_good_name:
		exchange_good_description:
		request_status:请求状态
	]
}
```

- 管理员根据用户id分页查看用户发布的信息 /getInfoByMemId

```api
请求方式：POST
入参：page、member_id
出参：
{
	"msg":"查询成功"
	"info":[
		info_id:
		sort_id:
		public_member_id
		good_name:
		good_description:
		status:交易状态
		public_date:
		scan_num:
		deal_member_id:
		request_member_id:
		exchange_good_name:
		exchange_good_description:
		request_status:请求状态
	]
}
```

#### 用户 /member

- 用户注册 /register

```api
请求方式：POST
入参：member_id、password、member_name、wechat_id、phone_num
出参：
{
	"msg":"注册成功"
}
```

- 用户登录 /login

```api
请求方式：POST
入参：member_id、password
出参：
{
	"msg":"登录成功"
	"token":token
}
```

- 用户注销 /loginOut

```api
请求方式：POST
入参：
出参：
{
	"msg":"注销成功"
}
```

- 用户查看个人信息 /getPersonInfo

```api
请求方式：GET
入参：member_id
出参：
{
	"msg":"查询成功"
	"member":member
}
```

- 用户修改个人信息 /updatePersonInfo

```api
请求方式：PUT
入参：member_id、password、member_name、wechat_id、phone_num
出参：
{
	"msg":"修改成功"
	"member":member
}
```

- 用户发布信息 /publishInfo

```api
请求方式：POST
入参：sort_id、public_member_id、good_id
出参：
{
	"msg":"发布成功"
	"info":info
}
```

- 用户分页查看个人发布的信息 /getInfoById

```api
请求方式：GET
入参：public_member_id
出参：
{
	"msg":"查询成功"
	"info":[
		info_id:
		sort_id:
		good_name:
		good_description:
		status:交易状态
		public_date:
		scan_num:
		deal_member_id:
		request_member_id:
		exchange_good_name:
		exchange_good_description:
	]
}
```

- 用户上传闲置物品 /uploadGood

```api
请求方式：POST
入参：good_name、good_description、owner_id、image
出参：
{
	"msg":"上传成功"
	"goods":goods
	"url":
}
```

- 发布用户审核交换请求 /checkRequest

```api
请求方式：PUT
入参：request_id、status
出参：
{
	"msg":"请求通过成功"/"请求拒绝成功"
	"RequestExchange":RequestExchange
}
```

- 发布信息用户查看成交用户的信息 /getByInfoId/getDealMem

```api
请求方式：GET
入参：info_id
出参：
{
	"msg":"查询成功"
	"Member":[
		member_name:
		wechat_id:
		phone_num:
	]
}
```

- 请求用户请求交换闲置物品 /requestExchange

```api
请求方式：POST
入参：request_member_id、info_id、exchange_good_id
出参：
{
	"msg":"请求成功"
	"RequestExchange":RequestExchange
}
```

#### 信息 /info

- 分页查询已发布的信息 /getInfo

```api
请求方式：GET
入参：page
出参：
{
	"msg":"查询成功"
	"info":info
}
```

- 分页模糊搜索已发布的信息 /getInfoByKeyword

```api
请求方式：GET
入参：page、Keyword
出参：
{
	"msg":"查询成功"
	"info":info
}
```

- 分页分类查询已发布的信息 /getInfoBySort

```api
请求方式：GET
入参：page、sort_id
出参：
{
	"msg":"查询成功"
	"info":info
}
```

- 分页分类模糊搜索已发布的信息 /getInfo/bySort/byKeyword

```api
请求方式：GET
入参：page、sort_id、Keyword
出参：
{
	"msg":"查询成功"
	"info":info
}
```