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

<title>订单列表页</title>
</head>
<body>

	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>


	<div class="container-fluid">
		<!-- 页面标题 -->
		<div class="row">
			<div class="col-md-12">
				<h1>订单列表页</h1>
			</div>
		</div>

		<!-- 提示信息 -->
		<c:if test="${ empty pageModel }">
			<div class="row">
				<div class="col-md-12">
					<p>${ msg }</p>
				</div>
			</div>
		</c:if>

		<!-- 订单列表信息 -->
		<div class="row">
			<div class="col-md-12">
				<c:if test="${ not empty pageModel }">
					<c:forEach items="${ pageModel.records }" var="order">
						<!-- 订单项头部 -->
						<div class="row">
							<div class="col-md-10">
								<ul class="list-inline">
									<li><p>订单号：${ order.oid }</p></li>
									<li><p>订单时间：${ order.ordertime }</p></li>
									<li><p>总金额：${ order.total }</p></li>
								</ul>
							</div>
							<div class="col-md-2">
							<p class="text-right">
											订单状态：
											<c:if test="${ order.state == 1 }">
												<a
													href="${ pageContext.servletContext.contextPath }/OrderServlet?method=toOrderInfo&oid=${ order.oid }">去付款</a>
											</c:if>
											<c:if test="${ order.state == 2 }">
			待发货
		</c:if>
											<c:if test="${ order.state == 3 }">
			待收货
		</c:if>
											<c:if test="${ order.state == 4 }">
			已签收
		</c:if>
										</p>
							</div>
						</div>

						<!-- 订单项内容 -->
						<div class="row">
							<div class="col-md-12">
								<table class="table table-bordered table-hover">
									<thead>
										<tr>
											<th>图片</th>
											<th>商品</th>
											<th>价格</th>
											<th>数量</th>
											<th>小计</th>
										</tr>
									</thead>
									<tbody>
										<c:forEach items="${ order.items }" var="item">
											<tr>
												<th><img alt="${ item.product.pname }"
													src="${ pageContext.servletContext.contextPath }/${ item.product.pimage_short }"
													width="200px" height="200px" /></th>
												<th>${ item.product.pname }</th>
												<th>${ item.product.shop_price }</th>
												<th>${ item.quantity }</th>
												<th>${ item.total }</th>
											</tr>
										</c:forEach>
									</tbody>
								</table>
							</div>
						</div>
					</c:forEach>
					<!-- 分页按钮 -->
					<jsp:include page="pagebar.jsp"></jsp:include>
				</c:if>
			</div>
		</div>
	</div>



	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>