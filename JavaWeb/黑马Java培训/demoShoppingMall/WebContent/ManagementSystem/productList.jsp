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
<title>商品列表</title>
</head>
<body>

	<div class="container-fluid">
		<div class="row">
			<div class="col-md-12">
				<h3>商品列表</h3>
				<hr />
			</div>
		</div>

		<!-- 添加按钮 -->
		<div class="row">
			<div class="col-md-12 text-right">
				<p>
					<input id="toAddProduct" type="button" value="添加" class="btn btn-default" />
				</p>
			</div>
		</div>

		<!-- 商品信息 -->
		<c:if test="${ empty pageModel || empty pageModel.records}">
			<div class="row">
				<div class="col-md-12">
					<p>暂无商品</p>
				</div>
			</div>

		</c:if>


		<c:if test="${ not empty pageModel && not empty pageModel.records }">
			<div class="row">
				<div class="col-md-12">
					<table class="table table-bordered table-hover">
						<thead>
							<tr>
								<th>序号</th>
								<th>图片</th>
								<th>商品</th>
								<th>价格</th>
								<th>是否热门(1热门，0不热门)</th>
								<th>编辑</th>
								<th>下架</th>
							</tr>
						</thead>
						<tbody>
							<c:forEach items="${ pageModel.records }" var="p"
								varStatus="status">
								<tr>
									<td>${ status.count }
									<td><img alt="${ p.pname }"
										src="${ pageContext.servletContext.contextPath }/${ p.pimage_short }"
										width="200px" height="200px" /></td>
									<td>${ p.pname }</td>
									<td>${ p.shop_price }</td>
									<td>${ p.is_hot }</td>
									<td><a
										href="${ pageContext.servletContext.contextPath }/AdminProductServlet?method=toModifyProduct&pid=${ p.pid }">编辑</a></td>
									<td><a
										href="${ pageContext.servletContext.contextPath }/AdminProductServlet?method=invalidProduct&pid=${ p.pid }">下架</a></td>
								</tr>
							</c:forEach>
						</tbody>
					</table>
				</div>
			</div>
		</c:if>

	</div>

	<!-- 分页模块 -->
	<jsp:include page="../jsp/pagebar.jsp"></jsp:include>

	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/ManagementSystem/js/productList.js"></script>

</body>
</html>