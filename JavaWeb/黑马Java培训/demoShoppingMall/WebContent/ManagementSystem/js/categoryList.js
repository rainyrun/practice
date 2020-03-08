$(function(){
	
	// 点击“添加”按钮
	$("#addCategory").click(function(){
		// 跳转到添加分类页面
		window.location.href = "/DemoShoppingMall01/AdminCategoryServlet?method=toAddCategory";
	});
	
	// 点击“删除”链接
	$(".deleteCategory").click(function(){
		if(confirm("确定删除?")){
			var url = "/DemoShoppingMall01/AdminCategoryServlet";
			var method = "deleteCategory";
			var cid = $(this).attr("cid");
			
			$.post(url, {method:method, cid:cid}, function(data){
				alert(data);
				window.location.href = "/DemoShoppingMall01/AdminCategoryServlet?method=getCategories";
			});
			
		}
	});
});
