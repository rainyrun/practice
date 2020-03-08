# 购物商城Servlet版

## 概述

前端页面

1. 首页
2. 登录
3. 注册
4. 商品详情
5. 购物车
6. 支付

功能点

账号：注册、激活、登录

用户：游客、注册用户、管理用户

商城：首页、分类、商品详情

订单：购物车、订单、支付

后台：商品管理、订单及状态

使用技术

Servlet

JDBC

数据库连接池 C3P0

Redis

## 数据库设计

1. 用户表

```sql
-- 用户表
create table customer (
	uid varchar(32) NOT NULL PRIMARY KEY, #用户编号
	username varchar(20) DEFAULT NULL, #用户名
	password varchar(20) DEFAULT NULL, #密码
	name varchar(20) DEFAULT NULL, #昵称
	email varchar(30) DEFAULT NULL, #邮箱
	phone varchar(20) DEFAULT NULL, #手机号
	birthday date DEFAULT NULL, #生日
	sex varchar(10) DEFAULT NULL, #性别
	state int(11) DEFAULT 0, #状态，0未激活，1已激活
	code varchar(64) DEFAULT NULL, #激活码
);
```

2. 分类表

```sql
create table category (
	cid varchar(32) PRIMARY KEY NOT NULL, #分类id
	cname varchar(20) DEFAULT NULL, #分类名称
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

3. 商品表

```sql
create table product (
	pid varchar(32) PRIMARY KEY NOT NULL, #商品编号
	pname varchar(20) DEFAULT NULL, #商品名
	market_price double DEFAULT NULL, #市场价
	shop_price double DEFAULT NULL, #商城价
	pimage varchar(200) DEFAULT NULL, #商品图片路径
	pdate date DEFAULT NULL, #上架时间
	is_hot int(11) DEFAULT NULL, #是否热门，0不热，1热
	pdesc varchar(255) DEFAULT NULL, #商品描述
	pflag int(11) DEFAULT 0, #商品标记，0未下架，1下架
	cid varchar(32) DEFAULT NULL, #分类id
	FOREIGN KEY (cid) REFERENCES category(cid)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

## 功能分析

1. 用户模块
	- 登录
	- 注册
		- 表单参数校验（js）
		- 接收参数，填充对象（BeanUtils）
		- 注册用户（服务）
		- 向用户发送激活邮件
		- 注册失败提示
2. 商品模块
	- 商品详情
	- 商品分类展示
	- 商品分页
3. 订单模块
	- 加入购物车
	- 生成订单
4. 管理后台
	- 商品增删改查

## 注册模块

### 需求概述

1. 在首页点击跳转到注册页面（需要经过servlet处理）
2. 在注册页面填写用户信息，用js做一些简单的校验
3. 将用注册到数据库
4. 注册成功，展示“注册成功，请到邮箱激活账号”。
	1. 生成激活码、跳转链接
	2. 将跳转链接用邮件发送给用户，激活账号
	3. 点击跳转链接，在数据库内查询激活码，如果有，则激活成功；如果没有，则激活失败
5. 注册失败，展示“注册失败”提示信息

### 数据库设计

用户数据：用户ID、姓名、昵称、密码、邮箱、手机号、生日、性别、注册状态、激活码

```sql
create table customer(
	uid varchar(32) PRIMARY KEY not null,
	username varchar(20) DEFAULT null,
	nickname varchar(20) DEFAULT null,
	password varchar(32) DEFAULT null,
	email varchar(32) DEFAULT null,
	phone varchar(20) DEFAULT null,
	birthday date DEFAULT null,
	sex varchar(10) DEFAULT null,
	state int DEFAULT 0, # 注册状态，0表示未激活
	code varchar(64) DEFAULT null
);
```

### 项目结构

```
前端

- header.jsp：注册入口
- register.jsp：用户注册页面
- info.jsp：提示注册成功或失败

后端

- CustomerServlet：用户登录、注册、激活的相关处理
	- toRegister()：跳转到注册页
	- register()：处理注册逻辑
	- active()：处理激活逻辑
- CustomerService：提供用户登录、注册、激活相关的服务
	- register()：注册用户到数据库
	- active()：激活用户
- CustomerDao：提供对用户的处理
	- add()：添加用户
	- update()：更新用户信息
	- queryByCode()：根据注册码查找用户
- Customer：用来封装用户数据
	- setter&getter
	- toString()
```

## 登录模块

### 需求概述

1. 在登录页面填写用户名(昵称、手机号)和密码，去数据库查找用户
2. 能找到则登录成功，跳转到首页，并显示用户昵称
3. 否则，提示登录失败

### 项目结构

```
前端

- header.jsp：登录入口，登录成功后返回到页面，显示用户信息
- login.jsp：登录页面，显示提示信息。

后端

- CustomerServlet：处理登录、退出
	- toLogin()：跳转到登录页面
	- login()：获取参数、检查是否登录成功、页面跳转、返回参数（用户昵称、sessionid）
	- logout()：退出、重定向到首页
- CustomerService
	- login()：判断是否登录成功（密码、激活状态、昵称）
- CustomerDao
	- queryByPassword()：通过密码查找用户
```

## 分类模块

### 需求概述

1. 查询所有分类，在首页展示分类
2. 商品分类列表，分页展示

### 数据库设计

分类：分类ID（主键）、分类名

```sql
create table category(
	cid varchar(32) PRIMARY KEY NOT NULL,
	cname varchar(30) DEFAULT NULL
);
```

### 项目结构

```
前端

- header.jsp：显示分类信息
- productsByCategory.jsp：显示分类商品列表（分页展示）

后端
	
- CategoryServlet：查询分类信息，查询某分类下的商品
	- categories：获取分类信息，传递给前端，并存储到redis
	- productsByCategory：获取某分类的商品列表、当前页面id，将PageModel(分页参数、商品列表)传给前端

- CategoryService：
	- getCategories：获取分类信息
	- getProductsByCategory：获取某分类某页的商品列表，包装PageModel返回

- CategoryDao：
	- queryCategories：查询分类信息，返回String数组
	- queryProductsByCategory：查询某分类的商品列表
```

## 商品模块

### 需求概述

1. 首页热门商品展示
2. 商品详情页

### 数据库设计

商品：商品ID（主键）、商品名、市场价格、促销价格、图片地址、缩略图地址、上架时间、是否热门、描述、标记（是否下架）、商品分类ID（外键）

```sql
create table product(
	pid varchar(32) PRIMARY KEY NOT NULL,
	pname varchar(50) DEFAULT NULL,
	market_price double DEFAULT NULL,
	shop_price double DEFAULT NULL,
	pimage varchar(200) DEFAULT NULL,
	pimage_short varchar(200) DEFAULT NULL,
	pdate date DEFAULT NULL,
	is_hot int DEFAULT NULL, # 0表示非热门，1表示热门
	pdesc varchar(255) DEFAULT NULL,
	pflag int DEFAULT 0, # 0表示上架，1表示下架
	cid varchar(32) DEFAULT NULL FOREIGN KEY (cid) REFERENCES category(cid)
);
```

### 项目结构

```
前端

- index.jsp：热门商品入口
- product.jsp：商品详情页

后端

- ProductServlet
	- hotProducts：获取前9个热门商品，传递给前端
	- productByPid：获取商品pid参数，获取商品详情，传递给前端
- ProductService
	- getHotProducts：获取前9个热门商品
	- getProductByPid：获取商品详情
- ProductDao
	- queryHotProducts：查询前9个热门商品
	- queryProductByPid：获取某商品详情
- Product：封装商品对象
	- setter&getter
```

## 购物车模块

购物车放在session的作用域里，session存储在redis里，以保证下次登录后，还可以查找到购物车里的内容

### 需求概述

1. 添加到购物车。如果购物车里没有该商品，直接加入购物车；如果购物车里有，就增加商品数量。
2. 购物车商品列表展示，包括删除商品、修改商品数量、勾选商品(js做)、计算订单总金额、提交订单按钮、清空全部商品

### 对象设计

购物车有以下特点：

1. 添加、删除等操作基本都是针对购物车自身。
2. 存放在session作用域里，不需要对数据库进行操作。

所以将购物车抽象成对象，将对购物车的操作抽象成方法(代替对数据库的操作)。而购物车的每个商品项，可以抽象成购物车商品项对象。

```java
// 购物车商品项
class CartItem {
	private Product prod;// 购物车中的商品，需要的信息为：商品缩略图、商品名、价格
	private int num;// 商品数量
	private double subTotal;// 小计

	// 修改商品数量
	public void setNum(int num){
		this.num = num;
		setSubTotal();
	}

	// 计算小计
	private setSubTotal(){
		this.subTotal = this.num * prod.getShop_price();
	}

	// 其他getter&setter
}

// 购物车
class Cart {
	private double total;// 商品总价
	Map<String, CartItem> cartItems;// 购物车商品项们

	// 添加商品到购物车
	public void addProduct(CartItem cartItem) { }
	// 删除购物项
	public void deleteProduct(String pid){ }
	// 清空购物车
	public void clear() { }
	// 购物车商品总价
	public double setTotal() { }
	// 修改商品数量
	public void modifyProduct(CartItem cartItem) { }

	// 其他setter&getter
}
```

### 项目结构

```
前端

- header.jsp：购物车入口（登录后展示）
- product.jsp：将商品“添加到购物车”入口、选择商品数量
- cart.jsp：购物车商品列表页，可删除商品、修改商品数量、勾选商品(待做)、计算订单总金额、提交订单按钮、清空全部商品

后端

- CartServlet
	- toCart：跳转到购物车页面
	- addToCart：获取参数，封装成CartItem对象，将商品添加到购物车
	- deleteFromCart：获取pid，从购物车中删除商品，重定向到购物车
	- modifyProduct：获取参数，封装成CartItem对象，修改商品数量，重定向到购物车
	- clear：清空购物车，重定向到购物车
- CartService
	- addToCart：将商品添加到购物车
	- deleteFromCart：从购物车中删除商品
	- modifyProduct：修改商品数量
	- clear：清空购物车
- Cart：封装Cart的操作
- CartItem：封装CartItem的操作
```

### 测试

1. 修改购物车中的商品数量，跳转到其他页面，再进入购物车，查看商品数量

## 订单模块

### 需求概述

1. 从购物车生成订单，同时清空购物车中对应的商品。
2. 填写订单信息，跳转到支付模块。
3. 在“我的订单”中分页显示某用户的所有订单、订单商品，每页显示3条订单。订单状态为：待付款、待发货、待收货、已签收。
4. 在“我的订单”页，点击“待付款”跳转到订单信息页。

### 对象设计

订单对象

```java
class Order{
	private String oid;// 订单编号
	private Date ordertime;// 订单生成时间
	private double total;// 订单总金额
	private int state;// 订单状态
	private String address;// 收货地址
	private String name;// 收货人
	private String phone;// 电话
	private Customer customer;// 下单用户
	private List<OrderItem> items;// 订单项

	// 计算订单总金额
	private void setTotal(){
		// 遍历订单项，将订单项的金额相加
	}

	// setter&getter
}
```

订单项对象

```java
class OrderItem{
	private String itemid;// 订单项id
	private int quantity;// 商品数量
	private double total;// 价格小计
	private Product product;// 订单项对应的商品
	private Order order;// 订单项对应的订单

	// 计算价格小计
	private void setTotal{
		// 取得商品价格 * 商品数量
	}

	// setter&getter
}
```

### 数据库设计

订单：订单ID、下单时间、总金额、订单状态、收货地址、收货人、电话、用户ID（外键）

```sql
create table `order`(
	`oid` varchar(32) PRIMARY KEY NOT NULL,
	ordertime datetime DEFAULT NULL,
	total double DEFAULT NULL,
	state int DEFAULT NULL,
	address varchar(30) DEFAULT NULL,
	name varchar(20) DEFAULT NULL,
	phone varchar(20) DEFAULT NULL,
	uid varchar(32) DEFAULT NULL,
	FOREIGN KEY (uid) REFERENCES customer (uid)
);
```

订单项：订单项ID、商品数量、价格小计、商品ID、订单ID（外键）

```sql
create table orderitem(
	itemid varchar(32) PRIMARY KEY NOT NULL,
	quantity int DEFAULT NULL,
	total double DEFAULT NULL,
	pid varchar(32) DEFAULT NULL,
	`oid` varchar(32) DEFAULT NULL,
	FOREIGN KEY (pid) REFERENCES product (pid),
	FOREIGN KEY (`oid`) REFERENCES `order` (`oid`)
);
```

### 项目结构

```
前端

- cart.jsp：提交订单的入口
- orderInfo.jsp：订单详情页，包括订单包含的商品、收货地址、收货人、选择银行等信息。点击“付款”跳转到支付页面。如果是已支付，则显示具体信息。
- header.jsp：“我的订单”入口
- orderList.jsp：用户已有订单列表，分页展示，每页显示3条订单，并展示每条订单包含的商品。

后端

- OrderServlet
	- toOrder：获取购物车中的商品、清空购物车、生成订单、跳转到订单提交页
	- toOrderList：获取到用户某页的订单，跳转到订单列表页
	- toOrderInfo：获取到某用户某订单到详情页
- OrderService
	- generateOrder：根据购物车中的信息，生成订单
	- getOrdersWithPage：根据分页信息，获取对应的订单，生成PageModel
	- getOrder：获取到某个订单的信息
- OrderDao
	- addOrder：添加订单
	- addOrderItem：添加订单项
	- queryOrdersByCustomerWithPage：查询某用户的某页的订单
	- queryOrderRecordsByCustomer：查询某用户的订单总数
	- queryOrderItemsByOrder：查询某订单的所有订单项
	- queryOrder：查询某个订单的信息
	- queryOrderItem：查询某个订单项的信息
```

### 测试

1. 购物车不为空，用户未登录时，提交订单。查看是否提示登录
2. 用户登录、购物车不为空时，提交订单。查看是否：生成订单（我的订单）、购物车清空、订单存储到数据库内
3. 订单为空时，查看订单
4. 订单列表中，点击“去付款”，查看跳转是否正确

## 支付模块

暂时不做

一般流程为

1. 从前端获取参数
2. 封装参数跳转到第三方支付页面
3. 支付成功后跳转到回调页面（事先在参数内传递）
4. 在回调页面处理支付结果

### 需求概述

1. 跳转到第三方支付
2. 解析返回的支付信息

### 项目结构

```
- PayServlet
	- toPay：处理提交的订单，并跳转到支付页面
```

## 管理后台

### 需求描述

1. 分为：分类管理、商品管理、订单管理（暂时未做）、用户管理（暂时未做）模块
2. 分类管理
	1. 展示分类列表
	2. 添加分类
	3. 修改已有分类（商品分类需要同时改变）
	4. 删除分类(只能删除无商品分类，后端返回是否删除成功）
3. 商品管理
	1. 分页展示全部商品
	2. 添加商品
	3. 修改商品
	4. 商品下架

### 项目结构

```
前端

新开一个 ManagementSystem 文件夹

- categoryList.jsp：分类列表页
- addOrModifyCategory.jsp：添加或修改分类
- productList.jsp：商品列表页，分类展示
- addOrModifyProduct.jsp：添加或修改分类

后端

分类管理

- AdminCategoryServlet
	- getCategories：获取分类信息，传递给前端页面
	- toAddCategory：跳转到添加分类页面
	- toModifyCategory：获取分类信息，跳转到修改分类页面
	- addOrModifyCategory：获取分类信息，根据cid的值，添加或修改分类，跳转到分类列表页
	- deleteCategory：删除分类，仅有分类下无数据的分类可删除
- CategoryService
	- getCategories：获取分类列表
	- addCategory：添加分类
	- updateCategory：修改分类
	- deleteCategory：删除分类
- CategoryDao
	- queryCategories：获取分类列表
	- add：添加分类
	- update：修改分类
	- delete：删除分类

商品管理

- AdminProductServlet
	- getProducts：获取商品信息，传递给前端页面
	- toAddProduct：跳转到添加商品页面
	- toModifyProduct：获取商品信息，跳转到修改商品页面
	- addOrModifyProduct：获取商品信息，根据pid的值，添加或修改商品，跳转到商品列表页
	- invalidProduct：下架商品
- AdminCategoryServlet
	- getCategoriesWithJson：获取分类，以json格式传给前端
- ProductService
	- getProductsByPage：获取商品列表
	- addProduct：添加商品
	- updateProduct：修改商品
- ProductDao
	- queryProductRecords：获取商品总数
	- queryProductsByPage：获取商品列表
	- add：添加商品
	- update：修改商品
```
