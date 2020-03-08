$(function(){
	// 获取分类
	var url = "/DemoShoppingMall01/AdminCategoryServlet";
	var method = "getCategoriesWithJson";
	// 显示在下拉菜单列表里
	$.post(url, {method:method}, function(data){
		// 清空select元素
		$("#selectCategory").html("");
		var prodcid = $("#cid").val();
		// 添加option元素
		$(data).each(function(index, element){
			var cname = element.cname;
			var cid = element.cid;
			if( prodcid != null && cid == prodcid)
				$("#selectCategory").append("<option value=" + cid + " selected='selected'>" + cname + "</option>");
			else
				$("#selectCategory").append("<option value=" + cid + ">" + cname + "</option>");
			
		});
	});
	
	$("#upload_pimage").change(function(){
		$("#pimage").attr("src",URL.createObjectURL($(this)[0].files[0]));
	});
	
	$("#upload_pimage_short").change(function(){
		$("#pimage_short").attr("src",URL.createObjectURL($(this)[0].files[0]));
	});
});