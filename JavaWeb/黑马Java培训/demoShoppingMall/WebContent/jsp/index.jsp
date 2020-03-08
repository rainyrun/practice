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
	
<style>
	a{
		overflow: hidden;
		white-space: nowrap;
		text-overflow: ellipsis;
	}
</style>

<title>商城首页</title>

</head>
<body>

	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>

	<div class="container-fluid">


		<div class="row">
			<div class="col-md-12">
				<h3>热门商品</h3>
			</div>
		</div>
		<div class="row">
			<!-- js填充商品 -->
			<div id="hotProducts"></div>
		</div>
	</div>

	<!-- footer -->
	<jsp:include page="footer.jsp"></jsp:include>

	<!-- js -->
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/hotProducts.js"></script>
	<script
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>