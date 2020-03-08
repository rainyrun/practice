$(function(){
//	$("#addStu").click(function(){
//		window.location.href="/DemoStuManagerBySSM/toAddStu";
//	});
	
	$(".delStu").click(function(){
		var sid = $(this).attr("sid");
		if(confirm("确认删除学生?")){
			var url = "/DemoStuManagerBySSM/deleteStu";
			var param = {sid:sid};
			$.post(url, param, function(){
				alert("已删除成功");
				window.location.reload();
			});
		}
		return false;
	});
});