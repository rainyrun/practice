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
<title>编辑商品</title>
</head>
<body>

	<div class="container-fluid">

		<div class="row">
			<div class="col-md-12">
				<h3>编辑商品</h3>
				<hr />
			</div>
		</div>

		<!-- 编辑商品 -->
		<div class="row">
			<div class="col-md-12">
				<form
					action="${ pageContext.servletContext.contextPath }/AdminProductServlet?method=addOrModifyProduct"
					method="post" enctype="multipart/form-data">

					<div class="form-group sr-only">
						<input type="hidden" name="pid" value="${ product.pid }" />
					</div>

					<div class="form-group">
						<label for="pname" class="control-label">商品名：</label> <input
							type="text" id="pname" name="pname" value="${ product.pname }"
							class="form-control" />
					</div>

					<div class="form-group">
						<label for="market_price" class="control-label">市场价格：</label> <input
							type="text" id="market_price" name="market_price"
							value="${ product.market_price }" class="form-control" />
					</div>

					<div class="form-group">
						<label for="shop_price" class="control-label">商城价格：</label> <input
							type="text" id="shop_price" name="shop_price"
							value="${ product.shop_price }" class="form-control" />
					</div>

					<div class="form-group">
							<img id="pimage" alt="${ product.pname }"
								src="${ pageContext.servletContext.contextPath }/${ product.pimage }">
							<br />
						<label for="upload_pimage" class="control-label">商品图片：</label> <input
							type="file" id="upload_pimage" name="pimage" />
					</div>

					<div class="form-group">
						
							<img id="pimage_short" alt="${ product.pname }"
								src="${ pageContext.servletContext.contextPath }/${ product.pimage_short }">
							<br />

						<label for="upload_pimage_short" class="control-label">缩略图：</label>
						<input type="file" id="upload_pimage_short" name="pimage_short" />
					</div>

					<div class="form-group">
						<input type="hidden" id="cid" value="${ product.cid }"/>
						<label for="selectCategory" class="control-label">选择分类：</label>
						<div>
							<select id="selectCategory" name="cid">
								<!-- jQuery获取分类数据 -->
							</select>
						</div>

					</div>

					<div class="form-group">
						<label for="is_hot" class="control-label">是否热门(1热门，0不热门)：</label> <input
							type="text" id="is_hot" name="is_hot" value="${ product.is_hot }"
							placeholder="1为热门，0不热门" class="form-control" />
					</div>

					<div class="form-group">
						<label for="pflag" class="control-label">商品状态(1下架，0上架)：</label> <input
							type="text" id="pflag" name="pflag" value="${ product.pflag }"
							placeholder="1为下架，0为上架" class="form-control" />
					</div>

					<div class="form-group">
						<label for="pdesc" class="control-label">商品描述：</label>
						<textarea rows="3" class="form-control" name="pdesc">${ product.pdesc }</textarea>
					</div>

					<div class="form-group">
						<input type="submit" value="提交" class="btn btn-default" />
					</div>

				</form>
			</div>
		</div>

	</div>




	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/ManagementSystem/js/addOrModifyProduct.js"></script>

</body>
</html>