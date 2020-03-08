<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link
	href="${ pageContext.servletContext.contextPath }/css/bootstrap.min.css"
	rel="stylesheet">

<title>导航条</title>
</head>
<body>

	<!-- 商城抬头 -->
	<div class="container-fluid">

		<div class="row">
			<div class="col-md-6">
				<h1>商城山寨版</h1>
			</div>
			<div class="col-md-6">
				<!-- 未登录时，显示“登录”、“注册”入口 -->
				<ul class="list-inline pull-right" style="padding:40px 0px 0px 0px;">
					<c:if test="${ empty loginCustomer }">

						<li><a
							href="${ pageContext.servletContext.contextPath }/CustomerServlet?method=toLogin">登录</a></li>
						<li><a
							href="${ pageContext.servletContext.contextPath }/CustomerServlet?method=toRegister">注册</a></li>
					</c:if>

					<!-- 已登录时，显示用户信息 -->
					<c:if test="${ not empty loginCustomer }">
						<li><a href="#">你好，${ loginCustomer.nickname }</a></li>
						<li><a
							href="${ pageContext.servletContext.contextPath }/CustomerServlet?method=logout">退出</a></li>
						<li><a
							href="${ pageContext.servletContext.contextPath }/CartServlet?method=toCart">购物车</a></li>
						<li><a
							href="${ pageContext.servletContext.contextPath }/OrderServlet?method=toOrderList&currentPage=1">我的订单</a></
						
					</c:if>
				</ul>
			</div>
		</div>

		<!-- 分类导航条 -->

		<nav class="navbar navbar-default">
			<div class="container-fluid">
				<!-- Collect the nav links, forms, and other content for toggling -->
				<div class="collapse navbar-collapse">
					<ul id="categories" class="nav navbar-nav">
						<li><a
							href="${ pageContext.servletContext.contextPath }/jsp/index.jsp">首页</a></li>
						<!-- js动态展示分类内容 -->
					</ul>

					<form class="navbar-form navbar-left sr-only">
						<div class="form-group">
							<input type="text" class="form-control" placeholder="Search">
						</div>
						<button type="submit" class="btn btn-default">Submit</button>
					</form>

				</div>
				<!-- /.navbar-collapse -->
			</div>
			<!-- /.container-fluid -->
		</nav>
	</div>





	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/header.js"></script>
	<script
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>