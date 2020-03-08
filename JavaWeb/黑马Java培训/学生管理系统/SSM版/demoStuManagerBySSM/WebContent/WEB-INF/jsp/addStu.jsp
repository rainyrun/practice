<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link
	href="${ pageContext.servletContext.contextPath }/css/bootstrap.css"
	rel="stylesheet">
<title>添加学生</title>
</head>
<body>
	<jsp:include page="header.jsp"></jsp:include>
	<div class="container-fluid">
		<h4>添加学生</h4>
		<hr>
		<form action="addStu" method="post">
			<div class="form-group">
				<label for="sname">姓名：</label> <input type="text"
					class="form-control" name="sname" id="sname" />
			</div>

			<div class="form-group">
				<label for="sex">性别：</label>
				<div id="sex">
					<label class="radio-inline"> <input type="radio" name="sex"
						value="男" />男
					</label> <label class="radio-inline"> <input type="radio"
						name="sex" value="女" />女
					</label>
				</div>
			</div>

			<div class="form-group">
				<label for="phone">电话：</label> <input type="text"
					class="form-control" name="phone" id="phone" />
			</div>

			<div class="form-group">
				<label for="hobby">爱好：</label>
				<div id="hobby">
					<label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="游泳" />游泳
					</label> <label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="读书" />读书
					</label> <label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="爬山" />爬山
					</label> <label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="跑步" />跑步
					</label>
				</div>
			</div>

			<div class="form-group">
				<label for="descript">简介：</label>
				<textarea class="form-control" rows="3" name="descript"
					id="descript"></textarea>
			</div>

			<input type="submit" class="btn btn-default" value="添加" />
		</form>
	</div>


	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.js"></script>
</body>
</html>