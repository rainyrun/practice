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

<title>注册</title>
</head>
<body>

	<div class="container-fluid">

		<!-- 标题 -->
		<div class="row">
			<div class="col-md-12">
				<h3>注册</h3>
			</div>
		</div>

		<!-- 注册表单 -->
		<div class="row">
			<div class="col-md-12">
				<form action="CustomerServlet?method=register" method="post"
					class="form-horizontal">
					<div class="form-group">
						<label for="username" class="col-md-2 control-label">姓名</label>
						<div class="col-md-6">
							<input class="form-control" type="text" name="username" id="username" />
						</div>
					</div>

					<div class="form-group">
						<label for="nickname" class="col-md-2 control-label">昵称</label>
						<div class="col-md-6">
							<input class="form-control" type="text" name="nickname" id="nickname" />
						</div>
					</div>

					<div class="form-group">
						<label for="password" class="col-md-2 control-label">密码</label>
						<div class="col-md-6">
							<input class="form-control" type="text" name="password" id="password" />
						</div>
					</div>

					<div class="form-group">
						<label for="email" class="col-md-2 control-label">邮箱</label>
						<div class="col-md-6">
							<input class="form-control" type="text" name="email" id="email" />
						</div>
					</div>

					<div class="form-group">
						<label for="phone" class="col-md-2 control-label">手机号</label>
						<div class="col-md-6">
							<input class="form-control" type="text" name="phone" id="phone" />
						</div>
					</div>

					<div class="form-group">
						<label for="birthday" class="col-md-2 control-label">生日</label>
						<div class="col-md-6">
							<input class="form-control" type="text" name="birthday" id="birthday" />
						</div>
					</div>

					<div class="form-group">
						<label for="sex" class="col-md-2 control-label">性别</label>
						<div class="col-md-6">
						<label class="radio-inline"> <input type="radio"
							name="sex" id="male" value="男">男
						</label> 
						<label class="radio-inline"> <input type="radio"
							name="sex" id="female" value="女">女
						</label> 
						</div>
						
					</div>
					
					<div class="form-group">
						<div class="col-md-6 col-md-offset-2">
							<input class="btn btn-default" type="submit" value="注册" />
						</div>
					</div>

				</form>
			</div>
		</div>

	</div>



	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>