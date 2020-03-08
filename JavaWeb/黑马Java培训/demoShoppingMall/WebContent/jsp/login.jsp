<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link
	href="${ pageContext.servletContext.contextPath }/css/bootstrap.min.css"
	rel="stylesheet">
<title>登录</title>
</head>
<body>
	<div class="container-fluid">
		<h1>登录</h1>

		<form action="CustomerServlet?method=login" method="post"
			class="form-horizontal">
			<div class="form-group">
				<label for="name" class="col-md-2 control-label">姓名</label>
				<div class="col-md-6">
					<input type="text" name="name" id="name"
						placeholder="请输入 用户名 或 昵称 或 手机号" class="form-control" />
				</div>
			</div>
			<div class="form-group">
				<label for="password" class="col-md-2 control-label">密码</label>
				<div class="col-md-6">
					<input type="password" id="password" name="password"
						class="form-control" placeholder="请输入密码">
				</div>
			</div>

			<div class="form-group">
				<div class="col-md-offset-2 col-md-6">
					<!-- 提示信息 -->
					<p class="text-danger">${ msg }</p>
					<button type="submit" class="btn btn-default">登录</button>
				</div>
			</div>
		</form>

	</div>


	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>