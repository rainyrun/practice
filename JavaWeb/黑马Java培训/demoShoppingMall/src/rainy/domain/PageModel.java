package rainy.domain;

import java.util.List;

public class PageModel {
	// 基本属性
	private int currentPage;// 当前页数，由用户指定 *
	private int pageSize = 8;// 每页显示的条数，固定的 *
	private int totalRecords;// 总记录条数，数据库查出来的 *
	private int totalPages;// 总页数，计算出来的 *
	private int startIndex;// 每页开始记录的索引，计算出来的 *
	private int prePage;// 上一页 *
	private int nextPage;// 下一页 *

	private List records;// 已经分好页的结果集

	// 扩展属性
	// 一共每页显示9个页码按钮
	private int startPage;// 开始页码
	private int endPage;// 结束页码

	// 完善属性
	private String url;
	
	// 构造函数
	public PageModel(int currentPage, int totalRecords) {
		this.currentPage = currentPage;
		this.totalRecords = totalRecords;
		totalPages = (totalRecords % pageSize == 0) ? (totalRecords / pageSize) : (totalRecords / pageSize + 1);
		startIndex = (currentPage - 1) * pageSize;
		prePage = currentPage - 1;
		nextPage = currentPage + 1;
	}

	public int getCurrentPage() {
		return currentPage;
	}

	public int getPageSize() {
		return pageSize;
	}

	public void setPageSize(int pageSize) {
		this.pageSize = pageSize;
		// 更新页面信息
		totalPages = (totalRecords % pageSize == 0) ? (totalRecords / pageSize) : (totalRecords / pageSize + 1);
		startIndex = (currentPage - 1) * pageSize;
		prePage = currentPage - 1;
		nextPage = currentPage + 1;
	}

	public int getTotalRecords() {
		return totalRecords;
	}

	public int getTotalPages() {
		return totalPages;
	}

	public int getStartIndex() {
		return startIndex;
	}

	public int getPrePage() {
		return prePage;
	}

	public int getNextPage() {
		return nextPage;
	}

	public List getRecords() {
		return records;
	}

	public void setRecords(List records) {
		this.records = records;
	}

	public int getStartPage() {
		return startPage;
	}

	private void setStartPage(int startPage) {
		this.startPage = startPage;
	}

	public int getEndPage() {
		return endPage;
	}

	private void setEndPage(int endPage) {
		this.endPage = endPage;
	}

	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	@Override
	public String toString() {
		return "PageModel [currentPage=" + currentPage + ", pageSize=" + pageSize + ", totalRecords=" + totalRecords
				+ ", totalPages=" + totalPages + ", startIndex=" + startIndex + ", prePage=" + prePage + ", nextPage="
				+ nextPage + ", startPage=" + startPage + ", endPage=" + endPage + ", url=" + url + "]";
	}
	
}
