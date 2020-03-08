// JavaScript方式
//function deleteStu(sid){
//	var flag = confirm("确定删除学生" + sid + "?");
//	if(flag){
//		// 在当前页面上打开超链接
//		windows.location.href="delStu";
//	}
//}

// jQuery方式
$(function(){
	$(".delStu").click(function(){
		var sid = $(this).attr("sid");
		var flag = confirm("确定删除学生" + sid + "?");
		if(flag){
			$.post("delStu", {"sid": sid}, function(){
				alert("删除成功");
				window.location.href="byPage";
			});
		}
		return false;
	});
});

/*
 * 如果是ajax发送的request，servlet无法对request进行请求转发或重定向
 */