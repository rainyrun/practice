<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Login</title>
</head>
<body>
<form action="login" method="post">
	用户名：<input type="text" name="username" /><br />
	密码：<input type="password" name="password" /><br />
	<input type="submit" value="登录" /><br />
	<span>没有账户密码？</span><a href="logup.jsp">点击注册</a>
</form>

</body>
</html>