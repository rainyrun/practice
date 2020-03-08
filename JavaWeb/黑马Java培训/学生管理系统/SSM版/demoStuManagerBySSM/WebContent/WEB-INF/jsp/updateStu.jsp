<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link
	href="${ pageContext.servletContext.contextPath }/css/bootstrap.css"
	rel="stylesheet">
<title>更新学生信息</title>
</head>
<body>

<jsp:include page="header.jsp"></jsp:include>
	<div class="container-fluid">
		<h3>更新学生</h3>
		<hr>
		<form action="updateStu" method="post">
		<div class="form-group">
		<input type="hidden" name="sid" value="${ stu.sid }" />
		</div>
		
			<div class="form-group">
				<label for="sname">姓名：</label>
				<input type="text" class="form-control" name="sname"
					id="sname" value="${ stu.sname }" />
			</div>
			
			<div class="form-group">
				<label for="sex">性别：</label>
				<div id="sex">
					<label class="radio-inline"> <input type="radio" name="sex"
						value="男" <c:if test="${ stu.sex == '男' }">checked</c:if> />男
					</label> <label class="radio-inline"> <input type="radio"
						name="sex" value="女"  <c:if test="${ stu.sex == '女' }">checked</c:if> />女
					</label>
				</div>
			</div>
			
			<div class="form-group">
				<label for="phone">电话：</label>
				<input type="text" class="form-control" name="phone"
					id="phone" value="${ stu.phone }" />
			</div>
			
			<div class="form-group">
				<label for="hobby">爱好：</label>
				<div id="hobby">
					<label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="游泳" <c:if test="${ fn:contains(stu.hobby, '游泳') }">checked</c:if>  />游泳
					</label> <label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="读书" <c:if test="${ fn:contains(stu.hobby, '读书') }">checked</c:if>  />读书
					</label> <label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="爬山" <c:if test="${ fn:contains(stu.hobby, '爬山') }">checked</c:if>  />爬山
					</label> <label class="checkbox-inline"> <input type="checkbox"
						name="hobby" value="跑步" <c:if test="${ fn:contains(stu.hobby, '跑步') }">checked</c:if>  />跑步
					</label>
				</div>
			</div>
			
			<div class="form-group">
				<label for="descript">简介：</label>
				<textarea class="form-control" rows="3" name="descript"
					id="descript">${ stu.descript }</textarea>
			</div>
			
			<input type="submit" class="btn btn-default" value="添加" />
		</form>
	</div>

	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.js"></script>
</body>
</html>