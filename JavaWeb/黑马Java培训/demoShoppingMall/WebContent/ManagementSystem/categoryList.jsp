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
<title>分类列表</title>
</head>
<body>
	<div class="container-fluid">
		<div class="row">
			<div class="col-md-12">
				<h3>分类列表</h3>
				<hr />
			</div>
		</div>

		<!-- 添加按钮 -->
		<div class="row">
			<div class="col-md-12 text-right">
				<p>
					<input id="addCategory" type="button" value="添加"
						class="btn btn-default" />
				</p>
			</div>
		</div>

		<div class="row">
			<div class="col-md-12"></div>
		</div>

		<!-- 分类信息 -->

		<c:if test="${ empty categories }">
			<div class="row">
				<div class="col-md-12">
					<p>暂无分类</p>
				</div>
			</div>
		</c:if>

		<c:if test="${ not empty categories }">
			<div class="row">
				<div class="col-md-12">
					<table class="table table-bordered table-hover">
						<thead>
							<tr>
								<th>序号</th>
								<th>分类</th>
								<th>操作</th>
							</tr>
						</thead>
						<tbody>
							<c:forEach items="${ categories }" var="c" varStatus="status">
								<tr>
									<td>${ status.count }</td>
									<td>${ c.cname }</td>
									<td>
										<ul class="list-inline">
											<li><a
												href="${ pageContext.servletContext.contextPath }/AdminCategoryServlet?method=toModifyCategory&cid=${ c.cid }&cname=${ c.cname }">修改</a></li>
											<li><a href="#" class="deleteCategory" cid="${ c.cid }">删除</a></li>
										</ul>
									</td>
								</tr>
							</c:forEach>
						</tbody>
					</table>
				</div>
			</div>
		</c:if>

	</div>





	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/ManagementSystem/js/categoryList.js"></script>

</body>
</html>