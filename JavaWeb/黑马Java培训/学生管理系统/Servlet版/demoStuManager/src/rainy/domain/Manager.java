package rainy.domain;

import java.util.List;

import rainy.service.StudentService;
import rainy.service.impl.StudentServiceImpl;

/**
 * 学生整体信息
 * 
 * @author runlei
 * @param <T>
 *
 */
public class Manager<T> {
	// 学生信息总条数
	private int totalItems;
	// 分页展示的条数，默认展示3条
	public static int pageSize = 3;
	// 当前是第几页
	private int currentPage = 1;
	// 共有几页
	private int totalPages;
	// 需要显示的学生列表
	private List<T> list;

	public int getTotalItems() {
		return totalItems;
	}

	public void setTotalItems(int totalItems) {
		this.totalItems = totalItems;
		// 更新总页数
		if(totalItems % pageSize == 0) {
			this.setTotalPages(totalItems / pageSize);
		}
		else
			this.setTotalPages(totalItems / pageSize + 1);
	}

	public int getPageSize() {
		return pageSize;
	}

	public static void setPageSize(int pageSize) {
		Manager.pageSize = pageSize;
	}

	public int getCurrentPage() {
		return currentPage;
	}

	public void setCurrentPage(int pageId) {
		this.currentPage = pageId;
	}

	public int getTotalPages() {
		return totalPages;
	}

	public void setTotalPages(int totalPages) {
		this.totalPages = totalPages;
	}
	public List<T> getList() {
		return list;
	}

	public void setList(List<T> list) {
		this.list = list;
	}

	@Override
	public String toString() {
		return "StuManager [totalItems=" + totalItems + ", pageItems=" + pageSize + ", pageId=" + currentPage
				+ ", totalPages=" + totalPages + "]";
	}
	
}
