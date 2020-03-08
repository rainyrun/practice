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
<title>提示信息</title>
</head>
<body>
	<!-- 导航条 -->
	<jsp:include page="header.jsp"></jsp:include>
	
	<div class="container-fluid">
		<h1>${ msg }</h1>
	</div>

	<!-- footer -->
	<jsp:include page="footer.jsp"></jsp:include>

	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/jquery-3.4.1.js"></script>
	<script type="text/javascript"
		src="${ pageContext.servletContext.contextPath }/js/bootstrap.min.js"></script>
</body>
</html>