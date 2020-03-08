package rainy.web.servlet;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import org.apache.commons.io.IOUtils;

import rainy.domain.PageModel;
import rainy.domain.Product;
import rainy.service.ProductService;
import rainy.service.impl.ProductServiceImpl;
import rainy.utils.MyBeanUtils;
import rainy.utils.UUIDUtils;
import rainy.web.base.BaseServlet;

/**
 * Servlet implementation class AdminProductServlet
 */
public class AdminProductServlet extends BaseServlet {
	private static final long serialVersionUID = 1L;
	
	private static ProductService prodService = new ProductServiceImpl();

	public String getProducts(HttpServletRequest request, HttpServletResponse response) {
		// 获取页面号参数
		int currentPage = Integer.parseInt(request.getParameter("currentPage"));
		// 获取该页的数据
		PageModel pageModel = prodService.getProductsByPage(currentPage);
		// 将pageModel存入request作用域
		request.setAttribute("pageModel", pageModel);
		// 跳转到商品列表页
		return "/ManagementSystem/productList.jsp";
	}

	// 跳转到添加商品页面
	public String toAddProduct(HttpServletRequest request, HttpServletResponse response) {
		return "/ManagementSystem/addOrModifyProduct.jsp";
	}
	
	// 跳转到修改商品页面
	public String toModifyProduct(HttpServletRequest request, HttpServletResponse response) {
		// 获取商品pid
		String pid = request.getParameter("pid");
		// 取得商品信息
		Product product = prodService.getProductByPid(pid);
		// 存储到request作用域
		request.setAttribute("product", product);
		// 跳转到修改商品页面
		return "/ManagementSystem/addOrModifyProduct.jsp";
	}

	// 添加或修改商品（参数包含图片）
	public String addOrModifyProduct(HttpServletRequest request, HttpServletResponse response) throws IOException {
		try{
			// 解析request里的参数
			DiskFileItemFactory fac = new DiskFileItemFactory();
			ServletFileUpload upload = new ServletFileUpload(fac);
			List<FileItem> list = upload.parseRequest(request);
			// 遍历集合，将参数存入map中
			Map<String, String> map = new HashMap<String, String>();
			for(FileItem item : list){
				if(item.isFormField()){
					// 是普通项
					map.put(item.getFieldName(), item.getString("utf-8"));
				}
				else{
					// 是上传项
					String filename = item.getName();// 文件名
					// 没有上传文件，则跳过
					if( filename == null || filename.equals("") )
						continue;
					// 将图片存储在image/product/文件夹下
					// 获取文件的存储路径
					String path = getServletContext().getRealPath("image/product/");
					System.out.println(path);
					File pimage = new File(path + filename);
					// 创建输出流对象
					OutputStream os = new FileOutputStream(pimage);
					// 获取输入流对象
					InputStream is = item.getInputStream();// 二进制数据
					// 传输
					IOUtils.copy(is, os);
					// 关闭资源
					os.close();
					is.close();
					// 将参数放入map
					String key = item.getFieldName();// 参数名
					String value = "image/product/" + filename;
					map.put(key, value);
				}
			}
			String pid = map.get("pid");
			Product prod = new Product();
			MyBeanUtils.populate(prod, map);
			if(pid == null || pid.equals("")) {
				// 如果是添加商品
				prod.setPid(UUIDUtils.getId());
				prod.setPdate(new Date());
				prodService.addProduct(prod);
			}
			else {
				// 如果是修改商品
				System.out.println("修改商品");
				String pimage = prod.getPimage();
				String pimage_short = prod.getPimage_short();
				Product oldProd = prodService.getProductByPid(pid);
				// 查看是否上传新的商品图
				if( pimage == null || pimage.equals("")) {
					System.out.println("没改大图");
					// 没有上传，则将原商品的图片路径复制过来
					prod.setPimage(oldProd.getPimage());
				}
				if( pimage_short == null || pimage_short.equals("")) {
					System.out.println("没改缩略图");
					// 没有上传，则将原商品的图片路径复制过来
					prod.setPimage_short(oldProd.getPimage_short());
				}
				prod.setPdate(oldProd.getPdate());
				prodService.updateProduct(prod);
			}
			
		} catch(Exception e){
			e.printStackTrace();
		}
		// 重定向到商品列表页
		response.sendRedirect("AdminProductServlet?method=getProducts&currentPage=1");
		return null;
	}

	public String invalidProduct(HttpServletRequest request, HttpServletResponse response) throws IOException {
		// 获取参数pid
		String pid = request.getParameter("pid");
		// 取得Product对象
		Product prod = prodService.getProductByPid(pid);
		// 修改Product对象
		prod.setPflag(1);
		// 更新数据库里的信息
		prodService.updateProduct(prod);
		// 重定向到商品列表页
		response.sendRedirect("AdminProductServlet?method=getProducts&currentPage=1");
		return null;
	}

}
/*
 * 注1: 几种传输方式
 * 1. 单字节传输（效率低，占用资源多）
 * int c;
 * while((c = is.read()) != -1)
 * 		os.write(c);
 * 2. 数组传输
 */
