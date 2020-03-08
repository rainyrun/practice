$(function(){
	// 点击“添加”按钮
	$("#toAddProduct").click(function(){
		// 跳转到添加分类页面
		window.location.href = "/DemoShoppingMall01/AdminProductServlet?method=toAddProduct";
	});
});
