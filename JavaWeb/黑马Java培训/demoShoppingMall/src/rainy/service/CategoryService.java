package rainy.service;

import java.util.List;

import rainy.domain.Category;
import rainy.domain.PageModel;
import rainy.domain.Product;

public interface CategoryService {
	/**
	 * 获取分类信息
	 * @return
	 */
	List<Category> getCategories();
	/**
	 * 获取某页的分类商品列表
	 * @param cid 分类ID
	 * @param currentPage 页面id
	 * @return
	 */
	PageModel getProductsByCategory(String cid, int currentPage);
	/**
	 * 添加分类
	 * @param cate
	 */
	void addCategory(Category cate);
	/**
	 * 更新分类名
	 * @param cate
	 */
	void updateCategory(Category cate);
	/**
	 * 删除分类，要求分类下没有商品才能删除，否则删除失败
	 * @param cid
	 * @return
	 */
	boolean deleteCategory(String cid);

}
