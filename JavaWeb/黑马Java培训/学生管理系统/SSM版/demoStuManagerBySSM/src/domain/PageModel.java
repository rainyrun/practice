package domain;

import java.util.List;

public class PageModel {
	// 基本属性
	private int currentPage;// 当前页数，由用户指定 *
	private int pageSize = 6;// 每页显示的条数，固定的 *
	private int totalRecords;// 总记录条数，数据库查出来的 *
	private int totalPages;// 总页数，计算出来的 *
	private int startIndex;// 每页开始记录的索引，计算出来的 *

	private List records;// 已经分好页的结果集

	// 扩展属性
	// 一共每页显示9个页码按钮
	private int startPage;// 开始页码
	private int endPage;// 结束页码

	// 完善属性
	private String url;

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

	public List getRecords() {
		return records;
	}

	public void setRecords(List records) {
		this.records = records;
	}

	public int getStartPage() {
		return startPage;
	}

	public void setStartPage(int startPage) {
		this.startPage = startPage;
	}

	public int getEndPage() {
		return endPage;
	}

	public void setEndPage(int endPage) {
		this.endPage = endPage;
	}

	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	public void setCurrentPage(int currentPage) {
		this.currentPage = currentPage;
	}

	public void setTotalRecords(int totalRecords) {
		this.totalRecords = totalRecords;
	}

	public void setTotalPages(int totalPages) {
		this.totalPages = totalPages;
	}

	public void setStartIndex(int startIndex) {
		this.startIndex = startIndex;
	}

	@Override
	public String toString() {
		return "PageModel [currentPage=" + currentPage + ", pageSize=" + pageSize + ", totalRecords=" + totalRecords
				+ ", totalPages=" + totalPages + ", startIndex=" + startIndex + ", startPage=" + startPage + ", endPage=" + endPage + ", url=" + url + "]";
	}
	
}
