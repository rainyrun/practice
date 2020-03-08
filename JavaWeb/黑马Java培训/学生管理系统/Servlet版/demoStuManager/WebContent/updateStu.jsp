<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>更新学生信息</title>
</head>
<body>
	<h1>更新学生信息</h1>
	<form action="updateStu" method="post">
		<input type="hidden" name="sid" value="${ stu.sid }" />
		<table>
			<tr>
				<td>姓名：</td>
				<td><input type="text" name="sname" value="${ stu.sname }"/></td>
			</tr>
			<tr>
				<td>性别：</td>
				<td>
				<input type="radio" name="sex" value="男" <c:if test="${ stu.sex == '男' }">checked</c:if> />男 
				<input type="radio" name="sex" value="女" <c:if test="${ stu.sex == '女' }">checked</c:if>/>女
				</td>
			</tr>
			<tr>
				<td>电话：</td>
				<td><input type="text" name="phone" value="${ stu.phone }"/></td>
			</tr>
			<tr>
				<td>爱好：</td>
				<td>
				<input type="checkbox" name="hobby" value="游泳" <c:if test="${ fn:contains(stu.hobby, '游泳') }">checked</c:if> />游泳
				<input type="checkbox" name="hobby" value="读书" <c:if test="${ fn:contains(stu.hobby, '读书') }">checked</c:if> />读书
				<input type="checkbox" name="hobby" value="爬山" <c:if test="${ fn:contains(stu.hobby, '爬山') }">checked</c:if> />爬山
				<input type="checkbox" name="hobby" value="跑步" <c:if test="${ fn:contains(stu.hobby, '跑步') }">checked</c:if> />跑步
				</td>
			</tr>
			<tr>
				<td>简介：</td>
				<td><textarea rows="3" cols="20" name="descript">${ stu.descript }</textarea></td>
			</tr>
			<tr>
				<td colspan="2"><input type="submit" value="更新" /></td>
			</tr>
		</table>
	</form>
</body>
</html>