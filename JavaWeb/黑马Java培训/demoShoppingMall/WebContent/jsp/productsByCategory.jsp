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
<title>分类列表页</title>
</head>
<body>
	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>


	<div class="container-fluid">

		<!-- 提示信息 -->
		<c:if test="${ empty pageModel.records }">
			<div class="row">
				<div class="col-md-12">
					<p>该分类没有商品</p>
				</div>
			</div>
		</c:if>

		<!-- 商品模块 -->
		<c:if test="${ not empty pageModel.records }">
			<div class="row">
				<c:forEach items="${ pageModel.records }" var="prod">
					<div class="col-md-3 text-center">
						<img alt="${ prod.pname }"
							src="${ pageContext.servletContext.contextPath }/${ prod.pimage_short }"
							width="200px" height="200px"><br />
						<a
							href="${ pageContext.servletContext.contextPath }/ProductServlet?method=productByPid&pid=${ prod.pid }">${ prod.pname }</a>
						<p>价格：${ prod.shop_price }</p>
					</div>
				</c:forEach>
			</div>

			<!-- 分页按钮 -->
			<jsp:include page="pagebar.jsp"></jsp:include>
		</c:if>

	</div>

	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>