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
<title>购物车</title>
<style type="text/css">
.table {
	padding: 20px;
}
</style>
</head>
<body>

	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>

	<div class="container-fluid">

		<!-- 标题 -->
		<div class="row">
			<div class="col-md-12">
				<h1>购物详情</h1>
			</div>
		</div>

		<!-- 提示信息 -->
		<div class="row">
			<div class="col-md-12">

				<c:if test="${ empty cart || empty cart.values }">
					<span>购物车为空</span>
					<br />
				</c:if>
			</div>
		</div>



		<!-- 购物车主体 -->
		<div class="row">
			<div class="container-fluid">
				<c:if test="${ not empty cart && not empty cart.values }">
					<!-- 购物车中的商品 -->
					<div class="row">
						<div class="col-md-12">
							<!-- 商品项列表 -->
							<table class="table table-bordered table-hover">
								<thead>
									<tr>
										<th>图片</th>
										<th>商品</th>
										<th>价格</th>
										<th>数量</th>
										<th>小计</th>
										<th>操作</th>
									</tr>
								</thead>
								<tbody>
									<!-- cart.values取得的是cart对象getValues的返回值 -->
									<c:forEach items="${ cart.values }" var="cartItem">
										<tr>
											<td><img alt="${ cartItem.prod.pname }"
												src="${ pageContext.servletContext.contextPath }/${ cartItem.prod.pimage_short }"
												width="200" height="200" /></td>
											<td>${ cartItem.prod.pname }</td>
											<td>${ cartItem.prod.shop_price }</td>
											<td><input type="text" value="${ cartItem.num }"
												id="num" pid="${ cartItem.prod.pid }" /></td>
											<td>${ cartItem.subTotal }</td>
											<td><a href="#" pid="${ cartItem.prod.pid }"
												class="deleteFromCart">删除</a></td>
										</tr>
									</c:forEach>
								</tbody>
							</table>
						</div>
					</div>

					<!-- 购物车总金额 -->
					<div class="row">
						<div class="col-md-12">
							<p class="text-right">总金额：${ cart.total } 元</p>
							<br />
						</div>
					</div>

					<!-- 清空or提交 -->
					<div class="row">
						<div class="col-md-12 text-right">
							<a
								href="${ pageContext.servletContext.contextPath }/CartServlet?method=clear">清空购物车</a>
							<input id="toOrder" type="button" value="提交订单" />
						</div>
					</div>
				</c:if>
			</div>
		</div>


	</div>

	<!-- footer -->
	<jsp:include page="footer.jsp"></jsp:include>

	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/cart.js"></script>
	<script
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>