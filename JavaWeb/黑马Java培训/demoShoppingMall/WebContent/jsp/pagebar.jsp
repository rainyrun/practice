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

<title>分页组件</title>
</head>
<body>

	<!-- 分页按钮 -->
	<div class="container-fluid">

		<div class="row">
			<div class="col-md-12">
				<ul class="list-inline">
					<li><span>第 ${ pageModel.currentPage } / ${ pageModel.totalPages }
							页</span></li>
					<li><span>每页显示 ${ pageModel.pageSize } 条</span></li>
					<li><span>共有 ${ pageModel.totalRecords } 条记录</span></li>
				</ul>

			</div>
		</div>

		<div class="row">
			<div class="col-md-12 text-center">
				<nav aria-label="Page navigation">
					<ul class="pagination">
						<!-- 首页、上一页按钮 禁用 -->
						<c:if test="${ pageModel.currentPage == 1}">
							<!-- 首页 -->
							<li class="disabled"><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=1">首页</a></li>
							<!-- 上一页 -->
							<li class="disabled"><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ pageModel.currentPage -1 }"
								aria-label="Previous">上一页</a></li>

						</c:if>

						<!-- 首页、上一页按钮 激活 -->
						<c:if test="${ pageModel.currentPage != 1}">
							<!-- 首页 -->
							<li><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=1">首页</a></li>
							<!-- 上一页 -->
							<li><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ pageModel.currentPage -1 }"
								aria-label="Previous">上一页</a></li>
						</c:if>
						<c:forEach var="i" begin="1" end="${ pageModel.totalPages }">
							<c:if test="${ i == pageModel.currentPage }">
								<li class="disabled"><a 
									href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ i }">
										${ i } </a>
							</c:if>
							<c:if test="${ i != pageModel.currentPage }">
								<li><a
									href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ i }">
										${ i } </a>
								<li>
							</c:if>
						</c:forEach>
						<!-- 下一页、尾页按钮 禁用 -->
						<c:if test="${ pageModel.currentPage == pageModel.totalPages}">
							<!-- 下一页 -->
							<li class="disabled"><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ pageModel.currentPage +1 }"
								aria-label="Next">下一页 </a></li>

							<!-- 尾页 -->
							<li class="disabled"><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ pageModel.totalPages }">尾页</a></li>

						</c:if>

						<!-- 下一页、尾页按钮 激活 -->
						<c:if test="${ pageModel.currentPage != pageModel.totalPages}">
							<!-- 下一页 -->
							<li><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ pageModel.currentPage +1 }"
								aria-label="Next">下一页 </a></li>

							<!-- 尾页 -->
							<li><a
								href="${ pageContext.servletContext.contextPath }/${ pageModel.url }&currentPage=${ pageModel.totalPages }">尾页</a></li>
						</c:if>
					</ul>
				</nav>
			</div>
		</div>
	</div>



	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>

</body>
</html>