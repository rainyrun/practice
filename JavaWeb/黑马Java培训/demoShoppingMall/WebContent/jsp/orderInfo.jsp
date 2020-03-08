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

<title>订单详情页</title>

</head>
<body>

	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>

	<div class="container-fluid">
		<!-- 标题 -->
		<div class="row">
			<div class="col-md-12">
				<h2>订单详情页</h2>
			</div>
		</div>

		<!-- 订单详细信息 -->
		<div class="row">
			<div class="col-md-12">
				<p>订单号：${ order.oid }</p>
			</div>
		</div>

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
						<!-- 订单项信息 -->
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

		<!-- 订单金额 -->
		<div class="row">
			<div class="col-md-12">
				<p class="text-right">总金额：${ order.total }</p>
			</div>
		</div>

		<!-- 收货信息标题 -->
		<div class="row">
			<div class="col-md-12">
				<h3>收货信息</h3>
			</div>
		</div>


		<div class="row">
			<div class="col-md-12">
				<!-- 收货信息表单 -->
				<form class="form-horizontal">
					<div class="form-group">
						<label for="name" class="col-md-4 control-label">收货人：</label>
						<div class="col-md-6">
							<input type="text" name="name" id="name" placeholder="请输入收货人姓名">
						</div>
					</div>

					<div class="form-group">
						<label for="address" class="col-md-4 control-label">收货地址：</label>
						<div class="col-md-6">
							<input type="text" name="address" id="address"
								placeholder="请输入收货地址">
						</div>
					</div>

					<div class="form-group">
						<label for="phone" class="col-md-4 control-label">电话：</label>
						<div class="col-md-6">
							<input type="tel" name="phone" id="phone" placeholder="请输入联系电话">
						</div>
					</div>

					<h3>选择银行</h3>

					<!-- 银行信息 -->
					<div class="form-group">
						<div class="col-md-12 text-center">
							<label class="radio-inline"> <input type="radio"
								name="bank" id="">招商银行
							</label> <label class="radio-inline"> <input type="radio"
								name="bank" id="">农商银行
							</label> <label class="radio-inline"> <input type="radio"
								name="bank" id="">工商银行
							</label> <label class="radio-inline"> <input type="radio"
								name="bank" id="">邮政储蓄
							</label>
						</div>
					</div>

					<div class="form-group">
						<div class="col-md-12 text-right">
							<input type="button" class="btn btn-default" id="toPay" value="去支付">
						</div>
					</div>
				</form>
			</div>
		</div>
	</div>


	<!-- js脚本 -->
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/hotProducts.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>