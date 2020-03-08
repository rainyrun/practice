<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>学生管理系统</title>
</head>
<body>
	<h1>欢迎使用学生管理系统</h1>
	<table border="1" width="80%" align="center">
		<tr>
			<form action="queryStu" method="post">
				<td colspan="7">
					按姓名查询：<input type="text" name="queryByName" />
					按性别查询：
					<select name="queryBySex">
						<option>--请选择--</option>
						<option>男</option>
						<option>女</option>
					</select>
					<input type="submit" value="查询">
				</td>
			</form>
			<td><a href="addStu.jsp">添加</a></td>
		</tr>
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
		<c:forEach items="${ stuManager.list }" var="stu">
			<tr>
				<td>${ stu.sid }</td>
				<td>${ stu.sname }</td>
				<td>${ stu.sex }</td>
				<td>${ stu.phone }</td>
				<td>${ stu.hobby }</td>
				<td>${ stu.descript }</td>
				<td>${ stu.create_time }</td>
				<td><a href="getStu?sid=${ stu.sid }">更新</a><span> </span><a
					href="#" class="delStu" sid="${ stu.sid }">删除</a></td>
			</tr>
		</c:forEach>
		<tr>
		<td colspan="8">
		<span>第 ${ stuManager.currentPage } / ${ stuManager.totalPages } 页    </span>
		<span>每页显示 ${ stuManager.pageSize } 条    </span>
		<span>共有 ${ stuManager.totalItems } 条记录    </span>
		<c:if test="${ stuManager.currentPage == 1}">[首页] | 上一页</c:if>
		<c:if test="${ stuManager.currentPage != 1}">
		[<a href="byPage?pageId=1">首页</a>] | 
		<a href="byPage?pageId=${ stuManager.currentPage -1 }">上一页</a>
		</c:if>
		<span>
			<c:forEach var="i" begin="1" end="${ stuManager.totalPages }">
				<c:if test="${ i == stuManager.currentPage }">
					<span>  ${ i }  </span>
				</c:if>
				<c:if test="${ i != stuManager.currentPage }">
					<a href="byPage?pageId=${ i }">  ${ i }  </a>
				</c:if>
			</c:forEach>
		</span>
		<c:if test="${ stuManager.currentPage == stuManager.totalPages}">下一页 | [尾页]</c:if>
		<c:if test="${ stuManager.currentPage != stuManager.totalPages}">
		<a href="byPage?pageId=${ stuManager.currentPage +1 }">下一页</a> | 
		[<a href="byPage?pageId=${ stuManager.totalPages }">尾页</a>]
		</c:if>
		</td>
		</tr>
	</table>
	<script type="text/javascript" src="js/jquery-3.4.1.js"></script>
	<script type="text/javascript" src="js/deleteStu.js"></script>
</body>
</html>