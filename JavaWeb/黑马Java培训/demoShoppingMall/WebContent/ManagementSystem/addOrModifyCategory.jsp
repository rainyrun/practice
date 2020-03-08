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
<title>编辑分类</title>
</head>
<body>

	<div class="container-fluid">

		<div class="row">
			<div class="col-md-12">
				<h3>编辑分类</h3>
				<hr />
			</div>
		</div>

		<!-- 添加或修改分类 -->
		<div class="row">
			<div class="col-md-12">
				<form
					action="${ pageContext.servletContext.contextPath }/AdminCategoryServlet?method=addOrModifyCategory"
					method="post">
					<div class="form-group">
						<label for="cname">分类名：</label> <input type="text" id="cname"
							name="cname" value="${ cname }" />
					</div>

					<div class="form-group">
						<input class="btn btn-default" type="submit" value="提交">
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