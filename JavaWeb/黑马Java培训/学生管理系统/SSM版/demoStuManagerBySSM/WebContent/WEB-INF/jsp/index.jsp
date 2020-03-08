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
	href="${ pageContext.servletContext.contextPath }/css/bootstrap.css"
	rel="stylesheet">
<title>学生管理系统</title>
</head>
<body>

	<jsp:include page="header.jsp"></jsp:include>

	<div class="container-fluid">
		<div class="row">
			<div class="col-md-12">
				<nav class="navbar navbar-default">
					<div class="container-fluid">
						<div class="collapse navbar-collapse"
							id="bs-example-navbar-collapse-1">
							<ul class="nav navbar-nav">
								<li><a href="/DemoStuManagerBySSM/index">首页</a></li>
							</ul>
							<form action="index" method="post"
								class="form-inline navbar-form navbar-left">
								<div class="form-group">
									<label for="queryByName" class="control-label">按姓名查询：</label> <input
										id="queryByName" type="text" name="queryByName"
										class="form-control" value="${ queryByName }" />
								</div>
								<div class="form-group">
									<label for="queryBySex" class="control-label">按性别查询：</label> <select
										name="queryBySex" id="queryBySex" class="form-control">
										<option>--请选择--</option>
										<option <c:if test="${ queryBySex == '男' }">selected</c:if>>男</option>
										<option <c:if test="${ queryBySex == '女' }">selected</c:if>>女</option>
									</select>
								</div>
								<input type="submit" class="btn btn-default" value="查询">
							</form>
							<ul class="nav navbar-nav navbar-right">
								<li><input id="addStu" type="button"
									class="btn btn-default navbar-btn" data-toggle="modal"
									data-target="#addStuModal" value="添加" /></li>
							</ul>
						</div>
						<!-- /.navbar-collapse -->
					</div>
					<!-- /.container-fluid -->
				</nav>
			</div>

			<div class="col-md-12">
				<hr>
				<table class="table table-striped">
					<thead>
						<tr>
							<td>编号</td>
							<td>姓名</td>
							<td>性别</td>
							<td>电话</td>
							<td>爱好</td>
							<td>简介</td>
							<td>添加时间</td>
							<td>操作</td>
						</tr>
					</thead>
					<tbody>
						<c:forEach items="${ pageModel.records }" var="stu">
							<tr>
								<td>${ stu.sid }</td>
								<td>${ stu.sname }</td>
								<td>${ stu.sex }</td>
								<td>${ stu.phone }</td>
								<td>${ stu.hobby }</td>
								<td>${ stu.descript }</td>
								<td>${ stu.create_time }</td>
								<td><a href="toUpdate?sid=${ stu.sid }">更新</a><span>
								</span><a href="#" class="delStu" sid="${ stu.sid }">删除</a></td>
							</tr>
						</c:forEach>
					</tbody>
				</table>
			</div>
		</div>
	</div>

	<!-- 添加学生(模态框) -->
	<div class="modal fade" tabindex="-1" role="dialog" id="addStuModal"
		aria-labelledby="myModalLabel">
		<div class="modal-dialog" role="document">
			<div class="modal-content">
				<div class="modal-header">
					<button type="button" class="close" data-dismiss="modal"
						aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
					<h4 class="modal-title" id="myModalLabel">添加学生</h4>
				</div>
				<div class="modal-body">
					<form action="addStu" method="post">
						<div class="form-group">
							<label for="sname">姓名：</label> <input type="text"
								class="form-control" name="sname" id="sname" />
						</div>

						<div class="form-group">
							<label for="sex">性别：</label>
							<div id="sex">
								<label class="radio-inline"> <input type="radio"
									name="sex" value="男" />男
								</label> <label class="radio-inline"> <input type="radio"
									name="sex" value="女" />女
								</label>
							</div>
						</div>

						<div class="form-group">
							<label for="phone">电话：</label> <input type="text"
								class="form-control" name="phone" id="phone" />
						</div>

						<div class="form-group">
							<label for="hobby">爱好：</label>
							<div id="hobby">
								<label class="checkbox-inline"> <input type="checkbox"
									name="hobby" value="游泳" />游泳
								</label> <label class="checkbox-inline"> <input type="checkbox"
									name="hobby" value="读书" />读书
								</label> <label class="checkbox-inline"> <input type="checkbox"
									name="hobby" value="爬山" />爬山
								</label> <label class="checkbox-inline"> <input type="checkbox"
									name="hobby" value="跑步" />跑步
								</label>
							</div>
						</div>

						<div class="form-group">
							<label for="descript">简介：</label>
							<textarea class="form-control" rows="3" name="descript"
								id="descript"></textarea>
						</div>

						<input type="submit" class="btn btn-default" value="添加" />
					</form>
				</div>
			</div>
		</div>
	</div>

	<jsp:include page="pagebar.jsp"></jsp:include>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/index.js"></script>
</body>
</html>