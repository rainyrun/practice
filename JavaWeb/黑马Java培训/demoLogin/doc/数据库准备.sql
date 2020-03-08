-- 数据库名 demoLogin
create database demoLogin;
-- 创建用户表

create table user(
	id int primary key auto_increment,
	username varchar(30),
	password varchar(30)
);