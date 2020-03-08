<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>添加学生</title>
</head>
<body>
	<h1>添加学生</h1>
	<form action="addStu" method="post">
		<table>
			<tr>
				<td>姓名：</td>
				<td><input type="text" name="sname" /></td>
			</tr>
			<tr>
				<td>性别：</td>
				<td>
				<input type="radio" name="sex" value="男" />男 
				<input type="radio" name="sex" value="女" />女
				</td>
			</tr>
			<tr>
				<td>电话：</td>
				<td><input type="text" name="phone" /></td>
			</tr>
			<tr>
				<td>爱好：</td>
				<td>
				<input type="checkbox" name="hobby" value="游泳" />游泳
				<input type="checkbox" name="hobby" value="读书" />读书
				<input type="checkbox" name="hobby" value="爬山" />爬山
				<input type="checkbox" name="hobby" value="跑步" />跑步
				</td>
			</tr>
			<tr>
				<td>简介：</td>
				<td><textarea rows="3" cols="20" name="descript"></textarea></td>
			</tr>
			<tr>
				<td colspan="2"><input type="submit" value="添加" /></td>
				
			</tr>
		</table>
	</form>
</body>
</html>