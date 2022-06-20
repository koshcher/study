import Post from "./Post";

const PostList = ({ posts, deletePost }) => {
  return (
    <div>
      {posts.map((post) =>
        <Post id={post.id} number={post.number} title={post.title} key={post.id} deletePost={deletePost} />
      )}
    </div>
  );
}

export default PostList;