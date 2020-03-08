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

<title>商品详情</title>
</head>
<body>
	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>

	<div class="container-fluid">

		<div class="row">
			<div class="col-md-12">
				<!-- 提示信息（3秒后消失） -->
				<div id="info">${ msg }</div>
			</div>
		</div>

		<div class="row">
			<div class="col-md-12">
				<!-- 页面标题 -->
				<h2>商品详情</h2>
			</div>
		</div>

		<!-- 商品详情 -->
		<div class="row">
			<div class="col-md-5">
				<img alt="商品图片"
					src="${ pageContext.servletContext.contextPath }/${product.pimage}" width="400" height="400">
			</div>
			<div class="col-md-7">
				<div class="row">
					<div class="col-md-12">
						<h3>${ product.pname }</h3>
						<p>商品ID：${ product.pid }</p>
						<p>市场价格：${ product.market_price }</p>
						<p>促销价格：${ product.shop_price }</p>
						<p>商品描述：${ product.pdesc }</p>
					</div>
				</div>

				<div class="row">
					<div class="col-md-12">
						<!-- 添加到购物车 -->
						<form id="addToCartForm"
							action="${ pageContext.servletContext.contextPath }/CartServlet"
							method="post"
							class="form-horizontal">
							<div class="form-group sr-only">
								<label for="pid" class="col-sm-2 control-label">pid：</label>
								<div class="col-md-6">
									<input type="hidden" name="pid" id="pid" value="${ product.pid }" />
								</div>
							</div>

							<div class="form-group">
								<label for="num" class="col-sm-2 control-label">商品数量：</label>
								<div class="col-md-6">
									<input type="text" name="num" id="num" value="1" />
								</div>
							</div>
							
							<div class="form-group">
								<div class="col-md-2 col-md-offset-8">
									<input type="button" value="添加到购物车" id="addToCart" class="btn btn-default" />
								</div>
							</div>

						</form>
					</div>
				</div>
			</div>
		</div>
	</div>

	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/addToCart.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>